int isGoodBCID_33(int bcid);
int isGoodBCID_216(int bcid);
int isGoodBCID_400(int bcid);

int isGoodEvent_PbPb2015(int run, int lb, int bcid=1)
{
	switch(run)
	{
		case 287259:	if(lb>=142 && lb<=632)
									{
										return isGoodBCID_400(bcid);
									}
									else  return 0;

		case 287224:	if((lb>=171 && lb<=265) || (lb>=520 && lb<=802))
									{
										return isGoodBCID_400(bcid);
									}
									else  return 0;

		case 287222:	if(lb>=261 && lb<=280)
									{
										return isGoodBCID_400(bcid);
									}
									else  return 0;

		case 287068:	if(lb>=500 && lb<=707)
									{
										return isGoodBCID_400(bcid);
									}
									else  return 0;

		case 287044:	if(lb>=251 && lb<=938)
									{
										return isGoodBCID_400(bcid);
									}
									else  return 0;

		case 287038:	if(lb>=143 && lb<=457)
									{
										return isGoodBCID_400(bcid);
									}
									else  return 0;

		case 286995:	if(lb>=9 && lb<=38)
									{
										return isGoodBCID_400(bcid);
									}
									else  return 0;

		case 286990:	if(lb>=183 && lb<=578)
									{
										return isGoodBCID_400(bcid);
									}
									else  return 0;

		case 286967:	if(lb>=67 && lb<=475)
									{
										return isGoodBCID_400(bcid);
									}
									else  return 0;

		case 286908:	if(lb>=143 && lb<=557)
									{
										return isGoodBCID_400(bcid);
									}
									else  return 0;

		case 286854:	if(lb>=433 && lb<=972)
									{
										return isGoodBCID_400(bcid);
									}
									else  return 0;

		case 286834:	if(lb>=153 && lb<=518)
									{
										return isGoodBCID_400(bcid);
									}
									else  return 0;		

		case 286767:	if(lb>=96 && lb<=397)
									{
										return isGoodBCID_216(bcid);
									}
									else  return 0;

		case 286748:	if(lb>=107 && lb<=368)
									{
										return isGoodBCID_216(bcid);
									}
									else  return 0;

		case 286717:	if(lb>=310 && lb<=477)
									{
										return isGoodBCID_33(bcid);
									}
									else  return 0;

		case 286711:	if(lb>=111 && lb<=235)
									{
										return isGoodBCID_33(bcid);
									}
									else  return 0;	

		case 286665:	if(lb>=156 && lb<=308)
									{
										return 1;
									}
									else  return 0;	

		default:		return -1;
	}
}



int isGoodBCID_33(int bcid)
{
	switch(bcid)
	{
		case 1:
		case 454:
		case 458:
		case 467:
		case 471:
		case 480:
		case 484:
		case 493:
		case 497:
		case 506:
		case 510:
		case 519:
		case 523:
		case 532:
		case 536:
		case 545:
		case 549:
		case 3119:
		case 3123:
		case 3132:
		case 3136:
		case 3145:
		case 3149:
		case 3158:
		case 3162:
		case 3171:
		case 3175:
		case 3184:
		case 3188:
		case 3197:
		case 3201:
		case 3210:
		case 3214:
			return 1;
		default:	return 0;
	}
}

int isGoodBCID_216(int bcid)
{
	switch(bcid)
	{
		case 1:
		case 5:
		case 14:
		case 18:
		case 27:
		case 31:
		case 40:
		case 44:
		case 53:
		case 57:
		case 66:
		case 70:
		case 79:
		case 83:
		case 92:
		case 96:
		case 105:
		case 109:
		case 118:
		case 122:
		case 131:
		case 135:
		case 144:
		case 148:
		case 184:
		case 188:
		case 197:
		case 201:
		case 210:
		case 214:
		case 223:
		case 227:
		case 236:
		case 240:
		case 249:
		case 253:
		case 262:
		case 266:
		case 275:
		case 279:
		case 288:
		case 292:
		case 301:
		case 305:
		case 314:
		case 318:
		case 327:
		case 331:
		case 892:
		case 896:
		case 905:
		case 909:
		case 918:
		case 922:
		case 931:
		case 935:
		case 944:
		case 948:
		case 957:
		case 961:
		case 970:
		case 974:
		case 983:
		case 987:
		case 996:
		case 1000:
		case 1009:
		case 1013:
		case 1022:
		case 1026:
		case 1035:
		case 1039:
		case 1075:
		case 1079:
		case 1088:
		case 1092:
		case 1101:
		case 1105:
		case 1114:
		case 1118:
		case 1127:
		case 1131:
		case 1140:
		case 1144:
		case 1153:
		case 1157:
		case 1166:
		case 1170:
		case 1179:
		case 1183:
		case 1192:
		case 1196:
		case 1205:
		case 1209:
		case 1218:
		case 1222:
		case 1783:
		case 1787:
		case 1796:
		case 1800:
		case 1809:
		case 1813:
		case 1822:
		case 1826:
		case 1835:
		case 1839:
		case 1848:
		case 1852:
		case 1861:
		case 1865:
		case 1874:
		case 1878:
		case 1887:
		case 1891:
		case 1900:
		case 1904:
		case 1913:
		case 1917:
		case 1926:
		case 1930:
		case 1966:
		case 1970:
		case 1979:
		case 1983:
		case 1992:
		case 1996:
		case 2005:
		case 2009:
		case 2018:
		case 2022:
		case 2031:
		case 2035:
		case 2044:
		case 2048:
		case 2057:
		case 2061:
		case 2070:
		case 2074:
		case 2083:
		case 2087:
		case 2096:
		case 2100:
		case 2109:
		case 2113:
		case 2674:
		case 2678:
		case 2687:
		case 2691:
		case 2700:
		case 2704:
		case 2713:
		case 2717:
		case 2726:
		case 2730:
		case 2739:
		case 2743:
		case 2752:
		case 2756:
		case 2765:
		case 2769:
		case 2778:
		case 2782:
		case 2791:
		case 2795:
		case 2804:
		case 2808:
		case 2817:
		case 2821:
		case 2857:
		case 2861:
		case 2870:
		case 2874:
		case 2883:
		case 2887:
		case 2896:
		case 2900:
		case 2909:
		case 2913:
		case 2922:
		case 2926:
		case 2935:
		case 2939:
		case 2948:
		case 2952:
		case 2961:
		case 2965:
		case 2974:
		case 2978:
		case 2987:
		case 2991:
		case 3000:
		case 3004:
		case 3043:
		case 3047:
		case 3056:
		case 3060:
		case 3069:
		case 3073:
		case 3082:
		case 3086:
		case 3095:
		case 3099:
		case 3108:
		case 3112:
		case 3121:
		case 3125:
		case 3134:
		case 3138:
		case 3147:
		case 3151:
		case 3160:
		case 3164:
		case 3173:
		case 3177:
		case 3186:
		case 3190:
			return 1;
		default:	return 0;
	}
}

int isGoodBCID_400(int bcid)
{
	switch(bcid)
	{
		case 12:
		case 16:
		case 25:
		case 29:
		case 38:
		case 42:
		case 51:
		case 55:
		case 64:
		case 68:
		case 104:
		case 108:
		case 117:
		case 121:
		case 130:
		case 134:
		case 143:
		case 147:
		case 156:
		case 160:
		case 169:
		case 173:
		case 182:
		case 186:
		case 195:
		case 199:
		case 208:
		case 212:
		case 221:
		case 225:
		case 234:
		case 238:
		case 247:
		case 251:
		case 287:
		case 291:
		case 300:
		case 304:
		case 313:
		case 317:
		case 326:
		case 330:
		case 339:
		case 343:
		case 352:
		case 356:
		case 365:
		case 369:
		case 378:
		case 382:
		case 391:
		case 395:
		case 404:
		case 408:
		case 446:
		case 450:
		case 459:
		case 463:
		case 472:
		case 476:
		case 485:
		case 489:
		case 498:
		case 502:
		case 511:
		case 515:
		case 524:
		case 528:
		case 537:
		case 541:
		case 550:
		case 554:
		case 563:
		case 567:
		case 576:
		case 580:
		case 589:
		case 593:
		case 629:
		case 633:
		case 642:
		case 646:
		case 655:
		case 659:
		case 668:
		case 672:
		case 681:
		case 685:
		case 694:
		case 698:
		case 707:
		case 711:
		case 720:
		case 724:
		case 733:
		case 737:
		case 746:
		case 750:
		case 759:
		case 763:
		case 772:
		case 776:
		case 812:
		case 816:
		case 825:
		case 829:
		case 838:
		case 842:
		case 851:
		case 855:
		case 864:
		case 868:
		case 877:
		case 881:
		case 890:
		case 894:
		case 903:
		case 907:
		case 916:
		case 920:
		case 929:
		case 933:
		case 942:
		case 946:
		case 955:
		case 959:
		case 995:
		case 999:
		case 1008:
		case 1012:
		case 1021:
		case 1025:
		case 1034:
		case 1038:
		case 1047:
		case 1051:
		case 1060:
		case 1064:
		case 1073:
		case 1077:
		case 1086:
		case 1090:
		case 1099:
		case 1103:
		case 1112:
		case 1116:
		case 1125:
		case 1129:
		case 1138:
		case 1142:
		case 1178:
		case 1182:
		case 1191:
		case 1195:
		case 1204:
		case 1208:
		case 1217:
		case 1221:
		case 1230:
		case 1234:
		case 1243:
		case 1247:
		case 1256:
		case 1260:
		case 1269:
		case 1273:
		case 1282:
		case 1286:
		case 1520:
		case 1524:
		case 1533:
		case 1537:
		case 1546:
		case 1550:
		case 1559:
		case 1563:
		case 1572:
		case 1576:
		case 1585:
		case 1589:
		case 1598:
		case 1602:
		case 1611:
		case 1615:
		case 1624:
		case 1628:
		case 1637:
		case 1641:
		case 1650:
		case 1654:
		case 1663:
		case 1667:
		case 1703:
		case 1707:
		case 1716:
		case 1720:
		case 1729:
		case 1733:
		case 1742:
		case 1746:
		case 1755:
		case 1759:
		case 1768:
		case 1772:
		case 1781:
		case 1785:
		case 1794:
		case 1798:
		case 1807:
		case 1811:
		case 1820:
		case 1824:
		case 1833:
		case 1837:
		case 1846:
		case 1850:
		case 1886:
		case 1890:
		case 1899:
		case 1903:
		case 1912:
		case 1916:
		case 1925:
		case 1929:
		case 1938:
		case 1942:
		case 1951:
		case 1955:
		case 1964:
		case 1968:
		case 1977:
		case 1981:
		case 1990:
		case 1994:
		case 2003:
		case 2007:
		case 2016:
		case 2020:
		case 2029:
		case 2033:
		case 2069:
		case 2073:
		case 2082:
		case 2086:
		case 2095:
		case 2099:
		case 2108:
		case 2112:
		case 2121:
		case 2125:
		case 2134:
		case 2138:
		case 2147:
		case 2151:
		case 2160:
		case 2164:
		case 2173:
		case 2177:
		case 2186:
		case 2190:
		case 2228:
		case 2232:
		case 2241:
		case 2245:
		case 2254:
		case 2258:
		case 2267:
		case 2271:
		case 2280:
		case 2284:
		case 2293:
		case 2297:
		case 2306:
		case 2310:
		case 2319:
		case 2323:
		case 2332:
		case 2336:
		case 2345:
		case 2349:
		case 2358:
		case 2362:
		case 2371:
		case 2375:
		case 2411:
		case 2415:
		case 2424:
		case 2428:
		case 2437:
		case 2441:
		case 2450:
		case 2454:
		case 2463:
		case 2467:
		case 2476:
		case 2480:
		case 2489:
		case 2493:
		case 2502:
		case 2506:
		case 2515:
		case 2519:
		case 2528:
		case 2532:
		case 2541:
		case 2545:
		case 2554:
		case 2558:
		case 2594:
		case 2598:
		case 2607:
		case 2611:
		case 2620:
		case 2624:
		case 2633:
		case 2637:
		case 2646:
		case 2650:
		case 2659:
		case 2663:
		case 2672:
		case 2676:
		case 2685:
		case 2689:
		case 2698:
		case 2702:
		case 2711:
		case 2715:
		case 2724:
		case 2728:
		case 2737:
		case 2741:
		case 2777:
		case 2781:
		case 2790:
		case 2794:
		case 2803:
		case 2807:
		case 2816:
		case 2820:
		case 2829:
		case 2833:
		case 2842:
		case 2846:
		case 2855:
		case 2859:
		case 2868:
		case 2872:
		case 2881:
		case 2885:
		case 2894:
		case 2898:
		case 2907:
		case 2911:
		case 2920:
		case 2924:
		case 2960:
		case 2964:
		case 2973:
		case 2977:
		case 2986:
		case 2990:
		case 2999:
		case 3003:
		case 3012:
		case 3016:
		case 3025:
		case 3029:
		case 3038:
		case 3042:
		case 3051:
		case 3055:
		case 3064:
		case 3068:
		case 3077:
		case 3081:
		case 3119:
		case 3123:
		case 3132:
		case 3136:
		case 3145:
		case 3149:
		case 3158:
		case 3162:
		case 3171:
		case 3175:
		case 3184:
		case 3188:
		case 3197:
		case 3201:
		case 3210:
		case 3214:
		case 3223:
		case 3227:
		case 3236:
		case 3240:
		case 3249:
		case 3253:
		case 3262:
		case 3266:
			return 1;
		default:	return 0;
	}
}
