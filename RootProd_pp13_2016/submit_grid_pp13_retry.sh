prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_13TeV.00277025.physics_MinBias.merge.AOD.f624_m1486 \
    --outDS=user.mizhou.data15_pp13.00277025.Jun14.cumu.pTcms_RETRY \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

