prun --exec "echo %IN > input.txt; sh myrun.sh "  \
    --outputs PDST.root \
    --extFile extractor.h,extractor.C,isGoodEvent_PbPb.C,myrun.sh,trigEff.root \
    --athenaTag 20.1.0.4 \
    --cmtConfig=x86_64-slc6-gcc48-opt \
    --match '*NTUP*' \
    --inDS data10_hi.00169693.physics_bulk.merge.NTUP_HI.r2111_r2768_p753 \
    --outDS user.mizhou.PbPb2.Jan12.pico.169693.3PC/ \
    --noBuild \
echo
echo



