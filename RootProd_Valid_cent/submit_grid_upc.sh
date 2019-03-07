prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00287281.physics_UPC.merge.AOD.f658_m1533 \
    --outDS=user.mizhou.data15_hi.00287281old.May03.UPC_EbyE.CUTS \
		--skipScout \
		--mergeOutput \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00287281.physics_UPC.recon.AOD.r7907/ \
    --outDS=user.mizhou.data15_hi.00287281new.May03.UPC_EbyE.CUTS \
		--skipScout \
		--mergeOutput \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00286748.physics_UPC.merge.AOD.f658_m1533 \
    --outDS=user.mizhou.data15_hi.00286748old.May03.UPC_EbyE.CUTS \
		--skipScout \
		--mergeOutput \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00286748.physics_UPC.recon.AOD.r7829/ \
    --outDS=user.mizhou.data15_hi.00286748new.May03.UPC_EbyE.CUTS \
		--skipScout \
		--mergeOutput \
    --outputs=myaod.root \
    --useRootCore

