prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00286711.physics_MinBias.merge.AOD.f655_m1533 \
    --outDS=user.mizhou.data15_hi.00286711.Mar07.CME \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00286717.physics_MinBias.merge.AOD.f655_m1533 \
    --outDS=user.mizhou.data15_hi.00286717.Mar07.CME \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00286748.physics_MinBias.merge.AOD.f657_m1533 \
    --outDS=user.mizhou.data15_hi.00286748.Mar07.CME \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_hi.00287281.physics_MinBias.merge.AOD.f657_m1533 \
    --outDS=user.mizhou.data15_hi.00287281.Mar07.CME \
    --outputs=myaod.root \
    --useRootCore

