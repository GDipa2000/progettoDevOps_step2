#!/bin/bash

# SLURM script for matrix multiplication job using Singularity

# Job configuration
#SBATCH --job-name=matrix-mult                # Imposta il nome del job a "matrix-mult"
#SBATCH --output=matrix_multiplication_out.txt # Reindirizza l'output standard del job a un file di testo
#SBATCH --error=matrix_multiplication_err.txt  # Reindirizza l'output degli errori a un file di testo
#SBATCH --time=00:05:00                        # Imposta la durata massima del job a 5 minuti
#SBATCH --ntasks=2                             # Richiede 2 compiti (di solito processi)
#SBATCH --cpus-per-task=1                      # Assegna 1 CPU per compito
#SBATCH --mem=4GB                              # Assegna 4GB di memoria RAM per il job

# Load necessary modules
module load singularity                        # Carica il modulo singularity se non è già caricato

# Run the Singularity container
srun singularity exec --bind $(pwd):/progettoDevOps_step2 ./matrix_multiplication.sif \
    $(pwd)/main /progettoDevOps_step2/matrixA.txt /progettoDevOps_step2/matrixB.txt
# Comando sopra spiegato:
# `srun` - esegue comandi in un ambiente di job SLURM
# `singularity exec` - esegue un comando all'interno del contenitore Singularity
# `--bind $(pwd):/progettoDevOps_step2` - monta la directory corrente (da cui lo script è eseguito) dentro il contenitore al percorso `/progettoDevOps_step2`
# `./matrix_multiplication.sif` - specifica il file del contenitore Singularity da usare
# `$(pwd)/main /progettoDevOps_step2/matrixA.txt /progettoDevOps_step2/matrixB.txt` - specifica i comandi/argomenti da eseguire all'interno del contenitore:
# - `$(pwd)/main` - percorso del programma da eseguire
# - `/progettoDevOps_step2/matrixA.txt` - primo file di input (matrice A)
# - `/progettoDevOps_step2/matrixB.txt` - secondo file di input (matrice B)