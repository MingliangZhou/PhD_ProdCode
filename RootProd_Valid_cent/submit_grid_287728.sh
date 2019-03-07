prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00287728.physics_MinBias.recon.AOD.r7874/ \
    --outDS=user.mizhou.data15_hi.00287728.May17.CENT_debug \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

