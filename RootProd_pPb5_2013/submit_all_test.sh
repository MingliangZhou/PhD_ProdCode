prun --exec "echo %IN > input.txt; sh myrun.sh "  \
    --outputs PDST.root \
    --extFile extractor.h,extractor_trigBranches.C,extractor.C,isGoodEvent_pPb.C,myrun.sh,trigEff.root,CombineTriggers.C,CombineTriggers.h \
    --athenaTag 20.1.0.4 \
    --cmtConfig=x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
    --inDS data13_hip.00218048.physics_MinBias.merge.NTUP_HI.r5813_p1729/ \
    --outDS user.mizhou.pPb.218048.Sep31.valid/ \
    --noBuild \
echo "218048 : $? " >>Log.txt
echo
echo

