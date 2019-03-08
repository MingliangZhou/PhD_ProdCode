#!/bin/zsh

Filename=submit_AMPT.sh 
Filename1=dw_AMPT.sh 
Nevents=1000
Bimp=12
OUTDS="user.mizhou.AMPT.May23.Bimp$Bimp."

for((RUN=250;RUN<300;RUN+=1)) 
do

    echo $RUN

    echo "prun --exec \"sh myrun.sh $Nevents $RUN %RNDM:1 $Bimp\"  \\" >>$Filename
    echo "    --excludeFile .svn,make_submit.sh,Ampt-v1.25t3-v2.25t3-Aug4,ampt.root,$Filename \\">>$Filename
    echo "    --extFile ampt-v1.25t3-v2.25t3.tgz  \\">>$Filename
    echo "    --outputs ampt.root \\" >>$Filename
    echo "    --outDS $OUTDS$RUN \\">>$Filename
    echo "    --nJobs 20 \\">>$Filename
    echo "    --mergeOutput \\">>$Filename
    #  echo "    --site ANALY_CERN_XROOTD \\">>$Filename

    #  echo "    --athenaTag 17.2.0 \\">>$Filename
    #  echo "    --noBuild \\">>$Filename
    echo "    --rootVer=\"5.34.01\" \\">>$Filename
    echo "    --cmtConfig=\"x86_64-slc5-gcc43-opt\" \\">>$Filename


    echo "echo \"$RUN : \$? \" >>Log.txt">>$Filename
    echo "echo">>$Filename
    echo "echo">>$Filename
    echo -e "\n\n">>$Filename
    echo "dq2-get -f \"*root*\" $OUTDS$RUN/" >>dqget.sh

done

