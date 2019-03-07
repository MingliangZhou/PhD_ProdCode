prun --exec "echo %IN > input.txt; sh myrun.sh "  \
    --outputs PDST.root \
    --extFile extractor.h,extractor_trigBranches.C,extractor.C,isGoodEvent_pPb.C,myrun.sh,trigEff.root,CombineTriggers.C,CombineTriggers.h \
    --athenaTag 20.1.0.4 \
    --cmtConfig=x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
    --inDS data13_hip.00218338.physics_MinBias.merge.NTUP_HI.r5813_p1729/ \
    --outDS user.mizhou.pPb.Oct29.pico.218338/ \
    --noBuild \
echo "218338 : $? " >>Log.txt
echo
echo

prun --exec "echo %IN > input.txt; sh myrun.sh "  \
    --outputs PDST.root \
    --extFile extractor.h,extractor_trigBranches.C,extractor.C,isGoodEvent_pPb.C,myrun.sh,trigEff.root,CombineTriggers.C,CombineTriggers.h \
    --athenaTag 20.1.0.4 \
    --cmtConfig=x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
    --inDS data13_hip.00218783.physics_MinBias.merge.NTUP_HI.r5813_p1729/ \
    --outDS user.mizhou.pPb.Oct29.pico.218783/ \
    --noBuild \
echo "218783 : $? " >>Log.txt
echo
echo

prun --exec "echo %IN > input.txt; sh myrun.sh "  \
    --outputs PDST.root \
    --extFile extractor.h,extractor_trigBranches.C,extractor.C,isGoodEvent_pPb.C,myrun.sh,trigEff.root,CombineTriggers.C,CombineTriggers.h \
    --athenaTag 20.1.0.4 \
    --cmtConfig=x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
    --inDS data13_hip.00218898.physics_MinBias.merge.NTUP_HI.r5813_p1729/ \
    --outDS user.mizhou.pPb.Oct29.pico.218898/ \
    --noBuild \
echo "218898 : $? " >>Log.txt
echo
echo

prun --exec "echo %IN > input.txt; sh myrun.sh "  \
    --outputs PDST.root \
    --extFile extractor.h,extractor_trigBranches.C,extractor.C,isGoodEvent_pPb.C,myrun.sh,trigEff.root,CombineTriggers.C,CombineTriggers.h \
    --athenaTag 20.1.0.4 \
    --cmtConfig=x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
    --inDS data13_hip.00219001.physics_MinBias.merge.NTUP_HI.r5813_p1729/ \
    --outDS user.mizhou.pPb.Oct29.pico.219001/ \
    --noBuild \
echo "219001 : $? " >>Log.txt
echo
echo

prun --exec "echo %IN > input.txt; sh myrun.sh "  \
    --outputs PDST.root \
    --extFile extractor.h,extractor_trigBranches.C,extractor.C,isGoodEvent_pPb.C,myrun.sh,trigEff.root,CombineTriggers.C,CombineTriggers.h \
    --athenaTag 20.1.0.4 \
    --cmtConfig=x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
    --inDS data13_hip.00219089.physics_MinBias.merge.NTUP_HI.r5813_p1729/ \
    --outDS user.mizhou.pPb.Oct29.pico.219089/ \
    --noBuild \
echo "219089 : $? " >>Log.txt
echo
echo

