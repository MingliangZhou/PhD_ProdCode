prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data16_13TeV.00309314.physics_MinBias.merge.AOD.f763_m1715  \
    --outDS=user.mizhou.data16_pp13.00309314.Nov13.cumu \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data16_13TeV.00309346.physics_MinBias.merge.AOD.f763_m1715  \
    --outDS=user.mizhou.data16_pp13.00309346.Nov13.cumu \
    --outputs=myaod.root \
    --useRootCore

