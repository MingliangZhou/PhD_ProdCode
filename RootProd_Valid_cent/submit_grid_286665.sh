prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00286665.physics_MinBias.recon.AOD.r7874/ \
    --outDS=user.mizhou.data15_hi.00286665.Jun27.CENT \
    --outputs=myaod.root \
		--mergeOutput \
    --useRootCore

