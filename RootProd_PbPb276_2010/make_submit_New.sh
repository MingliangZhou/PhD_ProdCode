#!/bin/zsh

runname()
{

 RUNNUMBER=$1
 FileName=$2
 tid[168665]=286159_00
 tid[168726]=286223_00
 tid[168759]=286168_00
 tid[168875]=287010_00
 tid[169045]=287813_00
 tid[169136]=287011_00
 tid[169175]=287012_00
 tid[169206]=286871_00
 tid[169207]=286868_00
 tid[169223]=288704_00
 tid[169224]=287812_00
 tid[169226]=286867_00
 tid[169270]=286866_00
 tid[169564]=287677_00
 tid[169566]=286141_00
 tid[169567]=286870_00
 tid[169627]=286869_00
 tid[169648]=287009_00
 tid[169693]=289069_00
 tid[169750]=287676_00
 tid[169751]=286147_00
 tid[169765]=289066_00
 tid[169783]=288701_00
 tid[169837]=286865_00
 tid[169838]=288703_00


 #tid[169839]=289735_00
 tid[169839]=312009_00


 tid[169864]=285236_00
 tid[169866]=289737_00
 tid[169884]=289702_00
 tid[169927]=289065_00
 tid[169961]=289208_00
 tid[169964]=286864_00
 tid[169966]=289068_00
 tid[170002]=289736_00
 tid[170004]=286862_00
 tid[170015]=287008_00
 tid[170016]=289207_00
 tid[170080]=287811_00
 tid[170082]=289067_00
 tid[170398]=289206_00
 tid[170432]=283945_00
 tid[170459]=286863_00
 tid[170467]=288702_00
 tid[170482]=286153_00

 if [ $RUNNUMBER -lt 169648 ]
 then
   echo "    --inDS data10_hi.00$RUNNUMBER.physics_bulk.ROOT.NTUP_HI.r2114_p456_tid${tid[$RUNNUMBER]} \\">> $FileName
   echo "    dq2-ls -r data10_hi.00$RUNNUMBER.physics_bulk.ROOT.NTUP_HI.r2114_p456_tid${tid[$RUNNUMBER]}   ">> check.sh
 else 
   echo "    --inDS data10_hi.00$RUNNUMBER.physics_bulk.ROOT.NTUP_HI.r2111_p456_tid${tid[$RUNNUMBER]} \\">> $FileName
   echo "    dq2-ls -r data10_hi.00$RUNNUMBER.physics_bulk.ROOT.NTUP_HI.r2111_p456_tid${tid[$RUNNUMBER]}   ">> check.sh
 fi 
}


#good sites ANALY_CYF, ANALY_BNL_LONG,ANALY_BNL_SHORT,ANALY_IHEP,ANALY_FZK,   ANALY_CPPM,ANALY_TRIUMF, 	ANALY_CSCS
Filename=submit_all_pDST.sh 

if [ -e $Filename ]
then
  rm $Filename
fi

if [ -e check.sh  ]
then
  rm check.sh
fi

if test $1"aa" = "cleanaa"
then
   exit 0
fi

rm dqget.sh

pass=2

OUTDS="user.jjia.pDST.28Aug2016."


echo "rm *.root">$Filename

RUNNO=0
for RUN in 169648 170482 170459 170398 170082 170080 170016 170015 170004 170002 169966 169964 169961 169927 169864 169839 169783 169765 169751 169750 169693 169627 169567 169566 169564 169270 169226 169224 169223 169207 169206 169175 169136 169045 
do
  echo $RUNNO "  " $RUN
  RUNNO=`expr $RUNNO + 1`
  
#  echo "     --excludedSite ANALY_TRIUMF_CVMFS,ANALY_RAL_XROOTD,ANALY_IHEP,ANALY_SARA,ANALY_CSCS,ANALY_RAL,ANALY_TRIUMF,ANALY_FZK,ANALY_PIC,ANALY_ARC,ANALY_QMUL \\">>$Filename
#  echo "prun --exec \"echo %IN > input.txt; root -l -q -b 'run_data.C(\\\"input.txt\\\",$pass,$RUN)' \"  \\" >>$Filename
  echo "prun --exec \"echo %IN > input.txt;  sh myrun.sh \" \\" >>$Filename
  echo "     --match '*NTUP*'    \\">>$Filename
  echo "     --excludeFile .svn,input.txt,$0,$Filename,Log.txt,check.sh,backup \\">>$Filename
  echo "     --outputs PDST.root\\">>$Filename
  echo "     --extFile extractor.h,isGoodEvent.C \\">>$Filename
  echo "     --mergeOutput \\">>$Filename
  echo "     --athenaTag 20.1.0.4\\">>$Filename
  echo "     --cmtConfig=x86_64-slc6-gcc48-opt \\">>$Filename
  runname $RUN $Filename
  echo "     --outDS $OUTDS$RUN/  \\">>$Filename
#  echo "     --nGBPerJob=MAX \\">>$Filename

  if [ $RUN -eq 169693 ]
  then
      echo "     --excludedSite=ANALY_ARC,ANALY_WEIZMANN-CREAM,ANALY_FMPhI-UNIBA, ANALY_INFN-MILANO-ATLASC,IFAE_DATADISK,TAIWAN-LCG2_DATADISK,INFN-MILANO-ATLASC_DATADISK,DESY-ZN_DATADISK,ANALY_TAIWAN_PNFS_SL6,ANALY_TAIWAN_SL6 ">>$Filename
  else
      echo "     --excludedSite=ANALY_ARC,ANALY_FMPhI-UNIBA,ANALY_INFN-MILANO-ATLASC,IFAE_DATADISK,TAIWAN-LCG2_DATADISK,INFN-MILANO-ATLASC_DATADISK,DESY-ZN_DATADISK,ANALY_TAIWAN_PNFS_SL6,ANALY_TAIWAN_SL6">>$Filename
  fi

  echo "echo \"$RUNNO $RUN : \$? \" >>Log.txt">>$Filename
  echo "echo">>$Filename
  echo "echo">>$Filename
  echo -e "\n\n">>$Filename
  echo "dq2-get -f \"*root*\" $OUTDS$RUN""_PDST.root/" >>dqget.sh
done

