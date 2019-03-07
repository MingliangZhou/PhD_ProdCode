int isGoodBCID_8(int bcid); //2012+2013
int isGoodBCID_72(int bcid); //2013
int isGoodBCID_206(int bcid); //2013
int isGoodBCID_296(int bcid); // 2013
int isGoodBCID_254(int bcid); // 2013
int isGoodBCID_144(int bcid); // 2013
int isGoodBCID_248(int bcid); // 2013

int isGoodEvent_pPb(int run, int lb, int bcid)
{
	switch(run)
	{
// run 2013, p+Pb (and Pb+p)

		case 219114:	if(lb>=112 && lb<=255)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 219111:	if((lb>=92 && lb<=406) || (lb>=411 && lb<=481))
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 219089:	if(lb>=105 && lb<=357)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 219055:	if(lb>=456 && lb<=751)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 219039:	return 0;

		case 219028:	if(lb>=151 && lb<=740)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 219001:	if(lb>=132 && lb<=437)
						{
							return isGoodBCID_248(bcid);
						}
						else  return 0;

		case 218968:	if((lb>=117 && lb<=308) || (lb>=310 && lb<=418))
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218940:	if(lb>=39 && lb<=335)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218898:	if((lb>=152 && lb<=183) || (lb>=197 && lb<=389))
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218829:	if(lb>=155 && lb<=279)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218783:	if((lb>=273 && lb<=419) || (lb>=527 && lb<=537))
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218771:	if(lb>=153 && lb<=277)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218751:	if((lb>=84 && lb<=206) || (lb>=247 && lb<=309))
						{
							return isGoodBCID_144(bcid);
						}
						else  return 0;

		case 218716:	if((lb>=435 && lb<=684) || (lb>=855 && lb<=1116))
						{
							return isGoodBCID_144(bcid);
						}
						else  return 0;

		case 218679:	if(lb>=588 && lb<=821)
						{
							return isGoodBCID_144(bcid);
						}
						else  return 0;

		case 218677:	if(lb>=358 && lb<=428)
						{
							return isGoodBCID_72(bcid);
						}
						else  return 0;

		case 218589:	if(lb>=375 && lb<=630)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218536:	return 0;

		case 218527:	return 0;

		case 218473:	if(lb>=105 && lb<=525)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218436:	if((lb>=206 && lb<=263) || (lb>=378 && lb<=506) || (lb>=549 && lb<=660))
						{
							return isGoodBCID_254(bcid);
						}
						else  return 0;

		case 218391:	if((lb>=414 && lb<=418) || (lb>=421 && lb<=538))
						{
							return isGoodBCID_254(bcid);
						}
						else  return 0;

		case 218338:	if(lb>=236 && lb<=597)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218301:	if(lb>=185 && lb<=541)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218279:	return 0;

		case 218224:	return 0;

		case 218223:	return 0;

		case 218222:	if(lb>=121 && lb<=153)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218213:	if(lb>=3 && lb<=158)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218197:	if(lb>=404 && lb<=526)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218179:	if(lb>=256 && lb<=599)
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218168:	if((lb>=73 && lb<=334) || (lb>=336 && lb<=390))
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218118:	if((lb>=67 && lb<=254) || (lb>=256 && lb<=393))
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;

		case 218048:	if((lb>=531 && lb<=602) || (lb>=604 && lb<=610) || (lb>=612 && lb<=650) || (lb>=747 && lb<=1112))
						{
							return isGoodBCID_296(bcid);
						}
						else  return 0;
	
		case 218036:	return 0;

		case 218035:	return 0;
		
		case 218024:	if(lb>=4 && lb<=116)
						{
							return isGoodBCID_206(bcid);
						}
						else  return 0;

		case 218006:	if((lb>=225 && lb<=320) || (lb>=322 && lb<=506))
						{
							return isGoodBCID_206(bcid);
						}
						else  return 0;

		case 217999:	if(lb>=293 && lb<=901)
						{
							return isGoodBCID_206(bcid);
						}
						else  return 0;

		case 217948:	return 0;
	
		case 217946:	return 0;	
	
// run 2012, p+Pb:

	// these two runs are not part of official GRL but in case you need them,
	// just uncomment this section and comment out the other two lines
	/*
		case 210186:	if(lb>=16 && lb<=102)
						{
							return isGoodBCID_8(bcid);
						}
						else  return 0;

		case 210185:	if(lb>=22 && lb<=84)
						{
							return isGoodBCID_8(bcid);
						}
						else  return 0;
	*/
	
		case 210186:	return 0;
						
		case 210185:	return 0;						

		case 210184:	
						if(lb>=377 && lb<=643)	// official GRL
						//if((lb>=377 && lb<=402) || (lb>=417 && lb<=643))	// suggested by Tomasz
						{
							return isGoodBCID_8(bcid);
						}
						else  return 0;
						
		default:		return -1;
	}

}


int isGoodBCID_8(int bcid)
{
	switch(bcid)
	{
		case 1:
		case 101:
		case 201:
		case 301:
		case 1786:
		case 1886:
		case 1986:
		case 2086:
					return 1;
		default:	return 0;
	}
}

int isGoodBCID_72(int bcid)
{
	switch(bcid)
	{
		case 1:
 		case 9:
 		case 18:
 		case 26:
 		case 35:
 		case 43:
 		case 52:
 		case 60:
 		case 69:
 		case 77:
 		case 86:
 		case 94:
 		case 103:
 		case 111:
 		case 120:
 		case 128:
 		case 137:
 		case 145:
 		case 154:
 		case 162:
 		case 171:
 		case 179:
 		case 188:
 		case 196:
 		case 1356:
 		case 1364:
 		case 1373:
 		case 1381:
 		case 1390:
 		case 1398:
 		case 1407:
 		case 1415:
 		case 1424:
 		case 1432:
 		case 1441:
 		case 1449:
 		case 1458:
 		case 1466:
 		case 1475:
 		case 1483:
 		case 1492:
 		case 1500:
 		case 1509:
 		case 1517:
 		case 1526:
 		case 1534:
 		case 1543:
 		case 1551:
 		case 2674:
 		case 2682:
 		case 2691:
 		case 2699:
 		case 2708:
 		case 2716:
 		case 2725:
 		case 2733:
 		case 2742:
 		case 2750:
 		case 2759:
 		case 2767:
 		case 2776:
 		case 2784:
 		case 2793:
 		case 2801:
 		case 2810:
 		case 2818:
 		case 2827:
 		case 2835:
 		case 2844:
 		case 2852:
 		case 2861:
 		case 2869:
 					return 1;
		default:	return 0;
	}
}

int isGoodBCID_206(int bcid)
{
	switch(bcid)
	{
		case 1:
 		case 9:
 		case 18:
 		case 26:
 		case 35:
 		case 43:
 		case 52:
 		case 60:
 		case 69:
 		case 77:
 		case 86:
 		case 94:
 		case 103:
 		case 111:
 		case 120:
 		case 128:
 		case 137:
 		case 145:
 		case 154:
 		case 162:
 		case 171:
 		case 179:
 		case 188:
 		case 196:
 		case 233:
 		case 241:
 		case 250:
 		case 258:
 		case 267:
 		case 275:
 		case 284:
 		case 292:
 		case 301:
 		case 309:
 		case 318:
 		case 326:
 		case 335:
 		case 343:
 		case 352:
 		case 360:
 		case 369:
 		case 377:
 		case 386:
 		case 394:
 		case 403:
 		case 411:
 		case 420:
 		case 428:
 		case 892:
 		case 900:
 		case 909:
 		case 917:
 		case 926:
 		case 934:
 		case 943:
 		case 951:
 		case 960:
 		case 968:
 		case 977:
 		case 985:
 		case 994:
 		case 1002:
 		case 1011:
 		case 1019:
 		case 1028:
 		case 1036:
 		case 1045:
 		case 1053:
 		case 1062:
 		case 1070:
 		case 1079:
 		case 1087:
 		case 1124:
 		case 1132:
 		case 1141:
 		case 1149:
 		case 1158:
 		case 1166:
 		case 1175:
 		case 1183:
 		case 1192:
 		case 1200:
 		case 1209:
 		case 1217:
 		case 1226:
 		case 1234:
 		case 1243:
 		case 1251:
 		case 1260:
 		case 1268:
 		case 1277:
 		case 1285:
 		case 1294:
 		case 1302:
 		case 1311:
 		case 1319:
 		case 1588:
 		case 1596:
 		case 1605:
 		case 1613:
 		case 1622:
 		case 1630:
 		case 1639:
 		case 1647:
 		case 1656:
 		case 1664:
 		case 1673:
 		case 1681:
 		case 1690:
 		case 1698:
 		case 1707:
 		case 1715:
 		case 1724:
 		case 1732:
 		case 1783:
 		case 1791:
 		case 1800:
 		case 1808:
 		case 1817:
 		case 1825:
 		case 1834:
 		case 1842:
 		case 1851:
 		case 1859:
 		case 1868:
 		case 1876:
 		case 1885:
 		case 1893:
 		case 1902:
 		case 1910:
 		case 1919:
 		case 1927:
 		case 1936:
 		case 1944:
 		case 1953:
 		case 1961:
 		case 1970:
 		case 1978:
 		case 2015:
 		case 2023:
 		case 2032:
 		case 2040:
 		case 2049:
 		case 2057:
 		case 2066:
 		case 2074:
 		case 2083:
 		case 2091:
 		case 2100:
 		case 2108:
 		case 2117:
 		case 2125:
 		case 2134:
 		case 2142:
 		case 2151:
 		case 2159:
 		case 2168:
 		case 2176:
 		case 2185:
 		case 2193:
 		case 2202:
 		case 2210:
 		case 2247:
 		case 2255:
 		case 2264:
 		case 2272:
 		case 2281:
 		case 2289:
 		case 2298:
 		case 2306:
 		case 2315:
 		case 2323:
 		case 2332:
 		case 2340:
 		case 2349:
 		case 2357:
 		case 2366:
 		case 2374:
 		case 2383:
 		case 2391:
 		case 2400:
 		case 2408:
 		case 2417:
 		case 2425:
 		case 2434:
 		case 2442:
 		case 2906:
 		case 2914:
 		case 2923:
 		case 2931:
 		case 2940:
 		case 2948:
 		case 2957:
 		case 2965:
 		case 2974:
 		case 2982:
 		case 2991:
 		case 2999:
 		case 3008:
 		case 3016:
 		case 3025:
 		case 3033:
 		case 3042:
 		case 3050:
 		case 3059:
 		case 3067:
					return 1;
		default:	return 0;
	}
}



int isGoodBCID_296(int bcid)
{
	switch(bcid)
	{
		case 1:
 		case 9:
 		case 18:
 		case 26:
 		case 35:
 		case 43:
 		case 52:
 		case 60:
 		case 69:
 		case 77:
 		case 86:
 		case 94:
 		case 103:
 		case 111:
 		case 120:
 		case 128:
 		case 137:
 		case 145:
 		case 154:
 		case 162:
 		case 171:
 		case 179:
 		case 188:
 		case 196:
 		case 233:
 		case 241:
 		case 250:
 		case 258:
 		case 267:
 		case 275:
 		case 284:
 		case 292:
 		case 301:
 		case 309:
 		case 318:
 		case 326:
 		case 335:
 		case 343:
 		case 352:
 		case 360:
 		case 369:
 		case 377:
 		case 386:
 		case 394:
 		case 403:
 		case 411:
 		case 420:
 		case 428:
 		case 892:
 		case 900:
 		case 909:
 		case 917:
 		case 926:
 		case 934:
 		case 943:
 		case 951:
 		case 960:
 		case 968:
 		case 977:
 		case 985:
 		case 994:
 		case 1002:
 		case 1011:
 		case 1019:
 		case 1028:
 		case 1036:
 		case 1045:
 		case 1053:
 		case 1062:
 		case 1070:
 		case 1079:
 		case 1087:
 		case 1124:
 		case 1132:
 		case 1141:
 		case 1149:
 		case 1158:
 		case 1166:
 		case 1175:
 		case 1183:
 		case 1192:
 		case 1200:
 		case 1209:
 		case 1217:
 		case 1226:
 		case 1234:
 		case 1243:
 		case 1251:
 		case 1260:
 		case 1268:
 		case 1277:
 		case 1285:
 		case 1294:
 		case 1302:
 		case 1311:
 		case 1319:
 		case 1356:
 		case 1364:
 		case 1373:
 		case 1381:
 		case 1390:
 		case 1398:
 		case 1407:
 		case 1415:
 		case 1424:
 		case 1432:
 		case 1441:
 		case 1449:
 		case 1458:
 		case 1466:
 		case 1475:
 		case 1483:
 		case 1492:
 		case 1500:
 		case 1509:
 		case 1517:
 		case 1526:
 		case 1534:
 		case 1543:
 		case 1551:
 		case 1588:
 		case 1596:
 		case 1605:
 		case 1613:
 		case 1622:
 		case 1630:
 		case 1639:
 		case 1647:
 		case 1656:
 		case 1664:
 		case 1673:
 		case 1681:
 		case 1690:
 		case 1698:
 		case 1707:
 		case 1715:
 		case 1724:
 		case 1732:
 		case 1783:
 		case 1791:
 		case 1800:
 		case 1808:
 		case 1817:
 		case 1825:
 		case 1834:
 		case 1842:
 		case 1851:
 		case 1859:
 		case 1868:
 		case 1876:
 		case 1885:
 		case 1893:
 		case 1902:
 		case 1910:
 		case 1919:
 		case 1927:
 		case 1936:
 		case 1944:
 		case 1953:
 		case 1961:
 		case 1970:
 		case 1978:
 		case 2015:
 		case 2023:
 		case 2032:
 		case 2040:
 		case 2049:
 		case 2057:
 		case 2066:
 		case 2074:
 		case 2083:
 		case 2091:
 		case 2100:
 		case 2108:
 		case 2117:
 		case 2125:
 		case 2134:
 		case 2142:
 		case 2151:
 		case 2159:
 		case 2168:
 		case 2176:
 		case 2185:
 		case 2193:
 		case 2202:
 		case 2210:
 		case 2247:
 		case 2255:
 		case 2264:
 		case 2272:
 		case 2281:
 		case 2289:
 		case 2298:
 		case 2306:
 		case 2315:
 		case 2323:
 		case 2332:
 		case 2340:
 		case 2349:
 		case 2357:
 		case 2366:
 		case 2374:
 		case 2383:
 		case 2391:
 		case 2400:
 		case 2408:
 		case 2417:
 		case 2425:
 		case 2434:
 		case 2442:
 		case 2479:
 		case 2487:
 		case 2496:
 		case 2504:
 		case 2513:
 		case 2521:
 		case 2530:
 		case 2538:
 		case 2547:
 		case 2555:
 		case 2564:
 		case 2572:
 		case 2581:
 		case 2589:
 		case 2598:
 		case 2606:
 		case 2615:
 		case 2623:
 		case 2674:
 		case 2682:
 		case 2691:
 		case 2699:
 		case 2708:
 		case 2716:
 		case 2725:
 		case 2733:
 		case 2742:
 		case 2750:
 		case 2759:
 		case 2767:
 		case 2776:
 		case 2784:
 		case 2793:
 		case 2801:
 		case 2810:
 		case 2818:
 		case 2827:
 		case 2835:
 		case 2844:
 		case 2852:
 		case 2861:
 		case 2869:
 		case 2906:
 		case 2914:
 		case 2923:
 		case 2931:
 		case 2940:
 		case 2948:
 		case 2957:
 		case 2965:
 		case 2974:
 		case 2982:
 		case 2991:
 		case 2999:
 		case 3008:
 		case 3016:
 		case 3025:
 		case 3033:
 		case 3042:
 		case 3050:
 		case 3059:
 		case 3067:
 		case 3104:
 		case 3112:
 		case 3121:
 		case 3129:
 		case 3138:
 		case 3146:
 		case 3155:
 		case 3163:
 		case 3172:
 		case 3180:
 		case 3189:
 		case 3197:
 		case 3206:
 		case 3214:
 		case 3223:
 		case 3231:
 		case 3240:
 		case 3248:
 		case 3257:
 		case 3265:
 		case 3274:
 		case 3282:
 		case 3291:
 		case 3299:
					return 1;
		default:	return 0;
	}
}

int isGoodBCID_254(int bcid)
{
	switch(bcid)
	{
		case 1:
 		case 9:
 		case 18:
 		case 26:
 		case 35:
 		case 43:
 		case 52:
 		case 60:
 		case 69:
 		case 77:
 		case 86:
 		case 94:
 		case 103:
 		case 111:
 		case 120:
 		case 128:
 		case 137:
 		case 145:
 		case 154:
 		case 162:
 		case 171:
 		case 179:
 		case 188:
 		case 196:
 		case 233:
 		case 241:
 		case 250:
 		case 258:
 		case 267:
 		case 275:
 		case 284:
 		case 292:
 		case 301:
 		case 309:
 		case 318:
 		case 326:
 		case 335:
 		case 343:
 		case 352:
 		case 360:
 		case 369:
 		case 377:
 		case 386:
 		case 394:
 		case 403:
 		case 411:
 		case 420:
 		case 428:
 		case 892:
 		case 900:
 		case 909:
 		case 917:
 		case 926:
 		case 934:
 		case 943:
 		case 951:
 		case 960:
 		case 968:
 		case 977:
 		case 985:
 		case 994:
 		case 1002:
 		case 1011:
 		case 1019:
 		case 1028:
 		case 1036:
 		case 1045:
 		case 1053:
 		case 1062:
 		case 1070:
 		case 1079:
 		case 1087:
 		case 1124:
 		case 1132:
 		case 1141:
 		case 1149:
 		case 1158:
 		case 1166:
 		case 1175:
 		case 1183:
 		case 1192:
 		case 1200:
 		case 1209:
 		case 1217:
 		case 1226:
 		case 1234:
 		case 1243:
 		case 1251:
 		case 1260:
 		case 1268:
 		case 1277:
 		case 1285:
 		case 1294:
 		case 1302:
 		case 1311:
 		case 1319:
 		case 1356:
 		case 1364:
 		case 1373:
 		case 1381:
 		case 1390:
 		case 1398:
 		case 1407:
 		case 1415:
 		case 1424:
 		case 1432:
 		case 1441:
 		case 1449:
 		case 1458:
 		case 1466:
 		case 1475:
 		case 1483:
 		case 1492:
 		case 1500:
 		case 1509:
 		case 1517:
 		case 1526:
 		case 1534:
 		case 1543:
 		case 1551:
 		case 1588:
 		case 1596:
 		case 1605:
 		case 1613:
 		case 1622:
 		case 1630:
 		case 1639:
 		case 1647:
 		case 1656:
 		case 1664:
 		case 1673:
 		case 1681:
 		case 1690:
 		case 1698:
 		case 1707:
 		case 1715:
 		case 1724:
 		case 1732:
 		case 1783:
 		case 1791:
 		case 1800:
 		case 1808:
 		case 1817:
 		case 1825:
 		case 1834:
 		case 1842:
 		case 1851:
 		case 1859:
 		case 1868:
 		case 1876:
 		case 1885:
 		case 1893:
 		case 1902:
 		case 1910:
 		case 1919:
 		case 1927:
 		case 1936:
 		case 1944:
 		case 1953:
 		case 1961:
 		case 1970:
 		case 1978:
 		case 2015:
 		case 2023:
 		case 2032:
 		case 2040:
 		case 2049:
 		case 2057:
 		case 2066:
 		case 2074:
 		case 2083:
 		case 2091:
 		case 2100:
 		case 2108:
 		case 2117:
 		case 2125:
 		case 2134:
 		case 2142:
 		case 2151:
 		case 2159:
 		case 2168:
 		case 2176:
 		case 2185:
 		case 2193:
 		case 2202:
 		case 2210:
 		case 2247:
 		case 2255:
 		case 2264:
 		case 2272:
 		case 2281:
 		case 2289:
 		case 2298:
 		case 2306:
 		case 2315:
 		case 2323:
 		case 2332:
 		case 2340:
 		case 2349:
 		case 2357:
 		case 2366:
 		case 2374:
 		case 2383:
 		case 2391:
 		case 2400:
 		case 2408:
 		case 2417:
 		case 2425:
 		case 2434:
 		case 2442:
 		case 2674:
 		case 2682:
 		case 2691:
 		case 2699:
 		case 2708:
 		case 2716:
 		case 2725:
 		case 2733:
 		case 2742:
 		case 2750:
 		case 2759:
 		case 2767:
 		case 2776:
 		case 2784:
 		case 2793:
 		case 2801:
 		case 2810:
 		case 2818:
 		case 2827:
 		case 2835:
 		case 2844:
 		case 2852:
 		case 2861:
 		case 2869:
 		case 2906:
 		case 2914:
 		case 2923:
 		case 2931:
 		case 2940:
 		case 2948:
 		case 2957:
 		case 2965:
 		case 2974:
 		case 2982:
 		case 2991:
 		case 2999:
 		case 3008:
 		case 3016:
 		case 3025:
 		case 3033:
 		case 3042:
 		case 3050:
 		case 3059:
 		case 3067:
					return 1;
		default:	return 0;
	}
}

int isGoodBCID_144(int bcid)
{
	switch(bcid)
	{
		case 1:
 		case 9:
 		case 18:
 		case 26:
 		case 35:
 		case 43:
 		case 52:
 		case 60:
 		case 69:
 		case 77:
 		case 86:
 		case 94:
 		case 103:
 		case 111:
 		case 120:
 		case 128:
 		case 137:
 		case 145:
 		case 154:
 		case 162:
 		case 171:
 		case 179:
 		case 188:
 		case 196:
 		case 892:
 		case 900:
 		case 909:
 		case 917:
 		case 926:
 		case 934:
 		case 943:
 		case 951:
 		case 960:
 		case 968:
 		case 977:
 		case 985:
 		case 994:
 		case 1002:
 		case 1011:
 		case 1019:
 		case 1028:
 		case 1036:
 		case 1045:
 		case 1053:
 		case 1062:
 		case 1070:
 		case 1079:
 		case 1087:
 		case 1124:
 		case 1132:
 		case 1141:
 		case 1149:
 		case 1158:
 		case 1166:
 		case 1175:
 		case 1183:
 		case 1192:
 		case 1200:
 		case 1209:
 		case 1217:
 		case 1226:
 		case 1234:
 		case 1243:
 		case 1251:
 		case 1260:
 		case 1268:
 		case 1277:
 		case 1285:
 		case 1294:
 		case 1302:
 		case 1311:
 		case 1319:
 		case 1356:
 		case 1364:
 		case 1373:
 		case 1381:
 		case 1390:
 		case 1398:
 		case 1407:
 		case 1415:
 		case 1424:
 		case 1432:
 		case 1441:
 		case 1449:
 		case 1458:
 		case 1466:
 		case 1475:
 		case 1483:
 		case 1492:
 		case 1500:
 		case 1509:
 		case 1517:
 		case 1526:
 		case 1534:
 		case 1543:
 		case 1551:
 		case 1783:
 		case 1791:
 		case 1800:
 		case 1808:
 		case 1817:
 		case 1825:
 		case 1834:
 		case 1842:
 		case 1851:
 		case 1859:
 		case 1868:
 		case 1876:
 		case 1885:
 		case 1893:
 		case 1902:
 		case 1910:
 		case 1919:
 		case 1927:
 		case 1936:
 		case 1944:
 		case 1953:
 		case 1961:
 		case 1970:
 		case 1978:
 		case 2674:
 		case 2682:
 		case 2691:
 		case 2699:
 		case 2708:
 		case 2716:
 		case 2725:
 		case 2733:
 		case 2742:
 		case 2750:
 		case 2759:
 		case 2767:
 		case 2776:
 		case 2784:
 		case 2793:
 		case 2801:
 		case 2810:
 		case 2818:
 		case 2827:
 		case 2835:
 		case 2844:
 		case 2852:
 		case 2861:
 		case 2869:
					return 1;
		default:	return 0;
	}
}

int isGoodBCID_248(int bcid)
{
	switch(bcid)
	{
 		case 1:
 		case 9:
 		case 18:
 		case 26:
 		case 35:
 		case 43:
 		case 52:
 		case 60:
 		case 69:
 		case 77:
 		case 86:
 		case 94:
 		case 103:
 		case 111:
 		case 120:
 		case 128:
 		case 137:
 		case 145:
 		case 154:
 		case 162:
 		case 171:
 		case 179:
 		case 188:
 		case 196:
 		case 233:
 		case 241:
 		case 250:
 		case 258:
 		case 267:
 		case 275:
 		case 284:
 		case 292:
 		case 301:
 		case 309:
 		case 318:
 		case 326:
 		case 335:
 		case 343:
 		case 352:
 		case 360:
 		case 369:
 		case 377:
 		case 386:
 		case 394:
 		case 403:
 		case 411:
 		case 420:
 		case 428:
 		case 892:
 		case 900:
 		case 909:
 		case 917:
 		case 926:
 		case 934:
 		case 943:
 		case 951:
 		case 960:
 		case 968:
 		case 977:
 		case 985:
 		case 994:
 		case 1002:
 		case 1011:
 		case 1019:
 		case 1028:
 		case 1036:
 		case 1045:
 		case 1053:
 		case 1062:
 		case 1070:
 		case 1079:
 		case 1087:
 		case 1124:
 		case 1132:
 		case 1141:
 		case 1149:
 		case 1158:
 		case 1166:
 		case 1175:
 		case 1183:
 		case 1192:
 		case 1200:
 		case 1209:
 		case 1217:
 		case 1226:
 		case 1234:
 		case 1243:
 		case 1251:
 		case 1260:
 		case 1268:
 		case 1277:
 		case 1285:
 		case 1294:
 		case 1302:
 		case 1311:
 		case 1319:
 		case 1356:
 		case 1364:
 		case 1373:
 		case 1381:
 		case 1390:
 		case 1398:
 		case 1407:
 		case 1415:
 		case 1424:
 		case 1432:
 		case 1441:
 		case 1449:
 		case 1458:
 		case 1466:
 		case 1475:
 		case 1483:
 		case 1492:
 		case 1500:
 		case 1509:
 		case 1517:
 		case 1526:
 		case 1534:
 		case 1543:
 		case 1551:
 		case 1588:
 		case 1596:
 		case 1605:
 		case 1613:
 		case 1622:
 		case 1630:
 		case 1639:
 		case 1647:
 		case 1656:
 		case 1664:
 		case 1673:
 		case 1681:
 		case 1690:
 		case 1698:
 		case 1707:
 		case 1715:
 		case 1724:
 		case 1732:
 		case 1783:
 		case 1791:
 		case 1800:
 		case 1808:
 		case 1817:
 		case 1825:
 		case 1834:
 		case 1842:
 		case 1851:
 		case 1859:
 		case 1868:
 		case 1876:
 		case 1885:
 		case 1893:
 		case 1902:
 		case 1910:
 		case 1919:
 		case 1927:
 		case 1936:
 		case 1944:
 		case 1953:
 		case 1961:
 		case 1970:
 		case 1978:
 		case 2015:
 		case 2023:
 		case 2032:
 		case 2040:
 		case 2049:
 		case 2057:
 		case 2066:
 		case 2074:
 		case 2083:
 		case 2091:
 		case 2100:
 		case 2108:
 		case 2117:
 		case 2125:
 		case 2134:
 		case 2142:
 		case 2151:
 		case 2159:
 		case 2168:
 		case 2176:
 		case 2185:
 		case 2193:
 		case 2202:
 		case 2210:
 		case 2479:
 		case 2487:
 		case 2496:
 		case 2504:
 		case 2513:
 		case 2521:
 		case 2530:
 		case 2538:
 		case 2547:
 		case 2555:
 		case 2564:
 		case 2572:
 		case 2581:
 		case 2589:
 		case 2598:
 		case 2606:
 		case 2615:
 		case 2623:
 		case 2674:
 		case 2682:
 		case 2691:
 		case 2699:
 		case 2708:
 		case 2716:
 		case 2725:
 		case 2733:
 		case 2742:
 		case 2750:
 		case 2759:
 		case 2767:
 		case 2776:
 		case 2784:
 		case 2793:
 		case 2801:
 		case 2810:
 		case 2818:
 		case 2827:
 		case 2835:
 		case 2844:
 		case 2852:
 		case 2861:
 		case 2869:
 		case 2906:
 		case 2914:
 		case 2923:
 		case 2931:
 		case 2940:
 		case 2948:
 		case 2957:
 		case 2965:
 		case 2974:
 		case 2982:
 		case 2991:
 		case 2999:
 		case 3008:
 		case 3016:
 		case 3025:
 		case 3033:
 		case 3042:
 		case 3050:
 		case 3059:
 		case 3067:
					return 1;
		default:	return 0;
	}
}
