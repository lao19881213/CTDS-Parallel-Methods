#!/bin/sh 

#for i in $(seq 10 -10 10)
#do
#	sbatch --account=$IVEC_PROJECT --time=12:00:00 --nodes=$i --ntasks-per-node=1  --dependency=singleton parallel_array_write.sh
#done

for i in $(seq 100 -1 1)
do
	#sbatch --account=$IVEC_PROJECT --time=00:10:00 --nodes=$i --ntasks-per-node=1 --dependency=singleton -p debugq parallel_array_write.sh
        sbatch --account=$IVEC_PROJECT --time=00:10:00 --nodes=1 --ntasks-per-node=1 --dependency=singleton generate_table.sh $i 
done




