prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_13TeV.00267360.physics_MinBias.merge.AOD.f597_m1441  \
    --outDS=user.mizhou.data15_pp13.00267360.Oct11.cumuCls \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_13TeV.00267367.physics_MinBias.merge.AOD.f597_m1441  \
    --outDS=user.mizhou.data15_pp13.00267367.Oct11.cumuCls \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_13TeV.00267385.physics_MinBias.merge.AOD.f597_m1441  \
    --outDS=user.mizhou.data15_pp13.00267385.Oct11.cumuCls \
    --outputs=myaod.root \
    --useRootCore

prun \
    --exec="echo %IN > input.txt; sh myrun.sh" \
    --inDS data15_13TeV.00267599.physics_MinBias.merge.AOD.f597_m1441  \
    --outDS=user.mizhou.data15_pp13.00267599.Oct11.cumuCls \
    --outputs=myaod.root \
    --useRootCore

