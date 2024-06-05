#!/bin/bash

# SBATCH Directives
# Queste direttive configurano le opzioni del job scheduler.

#SBATCH --job-name=matrix-mult                         # Nome del job, apparirà nei log e nei report del job scheduler.
#SBATCH --output=matrix_multiplication_out.txt         # File in cui verrà scritto l'output standard.
#SBATCH --error=matrix_multiplication_err.txt          # File in cui verrà scritto l'output degli errori.
#SBATCH --time=00:05:00                                # Tempo massimo di esecuzione, hh:mm:ss. Dopo questo tempo, il job sarà terminato.
#SBATCH --ntasks=2                                     # Numero totale di tasks da eseguire.
#SBATCH --cpus-per-task=1                              # Numero di CPU per task.
#SBATCH --mem=4GB                                      # Memoria totale allocata per il job.

# Preparazione dell'ambiente
# Carica il modulo Singularity, se non è già caricato. Questo modulo permette di usare Singularity per gestire i container.

module load singularity

# Esecuzione del container
# Questo comando usa srun per eseguire il container Singularity. Si binda la directory corrente a una directory nel container,
# e si esegue l'applicativo all'interno del container.

srun singularity exec --bind $(pwd):/progettoDevOps_step2 ./matrix_multiplication.sif mpiexec -np 2 /progettoDevOps_step2/main /progettoDevops_step2/matrixA.txt /progettoDevops_step2/matrixB.txt
