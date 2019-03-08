#!/bin/csh -f

Nevents=$1
Seed1=$2
Seed2=$3
Bimp=$4

if test "a" = $3"a"
then
 Seed=$Seed1
else
 Seed=`expr $Seed1 \* 1000 + $Seed2 \* 25`
fi

echo "Mingliang Nevents=$Nevents Seed=$Seed (Seed1=$Seed1  Seed2=$Seed2)"

if [ -e Ampt-v1.25t3-v2.25t3-Aug4 ]
then
  echo "directory exists"
else
  tar -xvzf ampt-v1.25t3-v2.25t3.tgz
fi


cd Ampt-v1.25t3-v2.25t3-Aug4
cp ../input_create.sh .
sh input_create.sh $Nevents $Seed $Bimp

sh exec
cd ana
cp ../../tree_di.C .
root -b -l <<EOF
.L tree_di.C+
tree_di($Nevents,$Seed) 
.q
EOF
mv *.root ../../
cd ../../
