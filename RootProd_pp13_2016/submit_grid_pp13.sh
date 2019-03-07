prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data16_13TeV.00299390.physics_MinBias_lbcustom.merge.AOD.r8219_p2645_tid09003617_00 \
    --outDS=user.mizhou.data16_pp13.00299390.July19.pico \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

