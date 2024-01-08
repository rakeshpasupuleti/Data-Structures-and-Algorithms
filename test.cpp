 
 #include<bits/stdc++.h>
using namespace std;


 string chooseandswap(string a){
        // Code Here
        
        int loc[26];
        
        for(int i=0; i<26; ++i) 
            loc[i]=-1;
            
        int len = a.length();
        
        for(int i=0; i<len; ++i) {
            
            if( loc[a[i]-'a']==-1)
                loc[a[i]-'a'] = i;
        }
        

    cout<<"The occurances of the array elements are"<<endl;
    for(int i=0; i<26; ++i) {
        cout<<i<<"  "<<char('a'+i)<<"  : "<<loc[i]<<endl;
    }
        
        for( int i=0; i<len; ++i) {
            
            int x = a[i]-'a';
            
            for(int j=0; j<x; ++j) {
                
                if( loc[j]!=-1 && loc[j] > i) {
                    
                    char originalchar = a[i];
                    char replacechar = char('a' +j); 
                    
                    string result="";
                    
                    for(int k=0; k<len; ++k) {
                        
                        if(a[k]==originalchar)
                            result += replacechar;
                        else if(a[k]==replacechar)
                            result +=originalchar;
                        else
                            result +=a[k];
                    }
                    
                   
                    return result;
                }
            }
            
           
        }
        
         return a;
         
    }
  

    int main() {
    
    cout<<chooseandswap("ufyoxlwtzhvkikerruognozgpzlldsrxxpnucjoerlobvsspnjvczxipwuczmuykllgqxwuqhkrfelurwrtwoenmyplmllwzxfpwbjmjtfqzsmrpdmnuqcgqrudffbeegtcieotzvjyoxrfaguwywfrpbuugxanevpobgjabubrruytasqbqxsgyocgldtpalfcroeuifobamvchnfxkxdilioxnkonvupokwktbaudpriwentonzyyhpxubmjyizosxanybkeqbomgdhwqgxrnoojpctnmudhrduregxwilkqrsohynambpxstqfikkpbojtuqsraebsvtgesufgxwdqrwxzgiqkwcfqsxhudlmagufaomgokmebkbdqjtcfvhypfhlksxlzuszkgiyqwctgeyypubvrkvhpcucxunyohzynjxffbynhzoxtrukbptttovqkiqyrqyezxjhzjugikfdbzodojwizrajbrjsjkyihjpismrdwwgywwdmgzwhsxrtqcnzmnjuwzeqlvtjscjoymcgnzofwhaojnpwcysyxwpkukwmmfcnuevhdlnbunredgcffwgeuvrohpawwelqlgyqunsoclufsynzutfpqyfznivkmgcxpcqjpizstuznsmophwexulxktuwibyhsbxdsfckbykqryhigdmdzzcjtxhbagisjivbpzoqyajryqzevnkummehjlijttdebyiqawjyyurwmqbhflbtzhbjvluogyvhydayblyzhpvthyamldglljuguqwborknwmnxxmyebwzluzzifftqopylfwmwqwlmjymikmpoiozfqynvggnwxlhejtazslmbkalwmakvpjchkpcqxpmucuanndnfobiabuzpwjmlvosfdwxanjwrfzfvcscqvltyhsnddaryolfuicuxotptswquqtmlghjnbysfylfpxnjhrfehyvdsttojmdwumhjogcvgncvmretjkaqkxtfrnvcbyzwngfbojyvzcqluxffjhvveravewahwzfjhlmwwmrvpjhlgoqpvllbenzkjzsiyxtfkgbhuucjelukbmcwanaeczpoahwygpfrxjasdebjsyutmwsmlsrntgdtpzrvryoojqgnvkypksiwqajductniwgzyzupyldhbmwywvnipygiaplvtgiddpcbozsokvynhwofrdpjbwrcnexhlhkqwntnolbyiznqwbxpfnagjrkwyjflrqbpfwcthgtpfghdihtnutvfnidntjymbbcgxgbgmuvscfxkmqzimxpbhsoabmnenrmkznsmjngoudagwaqizfjgyxiblxiyqukqkccvrijonkwjmntnuevuddwobeotaajkelgyvrmlbiwpxqcswxmadkqgqhztjjdoulosdcdgmzykrceoasqdfglvpkoztupqfdkkhpttorfitjyveoajwlemyvlrrajwftjmiefzvljqwhoavojtcqfansteudczynnjrtkmgtfeatfxjqqliwnvqhblmekmravjtfxbyehaxmxjfoupmileropfucrmcnxxswytdftautjbjgqvqdzjsromtfaxszunyuibbddxwpyfvrcnuewovkdqrdnmfhzdbjgcmjcjyaovtrkovgesshimnvyuexzfifjuoldpoumhnxxkfecynmkahkwlhvspcdltrpifluoytoizsmzfylihvguecmtergzixhpiegixuqwoevveifldmfhqtcwljwvgflpjtxjpqhdwfabngmruuykpbiameyskljvejgtboyxtyagepzyjakydtbpzzjlmthqenjfdhewhffmwgmhgxhjsiarjkdvfmnjbwqffwdpdkbzrpgzmoleylyixbfcntnqrfvzcboflrfegnevdrbcczmacrermsigxdfbevhsmowudcphttjwsvyvocmdwujwaqxglgyzuvvyzlfteqrylrvbviesepqgfnnsulrqipqicxdgnwgapcekmiesyuzfimyexrwignsikxqatxcibguppzhptgwduuhumgcutudfrvhmukuvqomhpuyjcvmxrwrdetaxpdegaouvyqsqefawzafbvtanrrsvmuubxbjapdvptnfashwtibxfwxsopnjdhefhfohuuelnrqpmalhioenlcibtxkweodnvswroacduvtivgpfvusiycjrzvpgmtthnszbudeoyzyvgoadkvnkxydxtsdflypaqqbltibsjcprsquclhoifrhbjmgxlvxdlbqhluzuwomogisrqicxzlyiyhhlefqqihztdynbobrxklqctsbseccejkpprfhzogsrghuvlluvwkzrfajjempnyefplmoatitzpowabqxybwpgzbrdpgtnmycxksxdatdphbsispivoadndussclfqljnybnbbigspikzcckxqmafpwxhaloqwxfuyuybcgttqgtsifparpfgncnnpbfmaliyhibkpudfcyymdpmuhrcuwpklspzscksmstwjqbrucrhfgtcnnekjwwwqlylqkfcebaotdhnfyungopubvgmtckmpkxhwelbflryrymwyijewaazygnrkadakcjhhvkoibnzbbyzjhdikgjimxzzzfbjjksqfehofupixnhixnqhvcphbqiaxjlhuezbigrqchyzwiktxccsetbfkkfjvrspxsrhaixdryeoiohhrmzxfcdrokbkdtzansiodhtuhxiposwhexelahdqueaxzcypwifzpywxxeolylsekxqmgtdazfyajypgguhxudwskldkywpivfvbaycbfcbpatxgpefkkccunheldvtacqccqgdwihnkaksrqxbczfwondzqyvrblvfcdlansnxuzpnpopsquqehvgawbtxmqeqtpqgjddfeutukkoaegfoelqaolzcbdtuvlcgrhmvbhrnrhovovlsibsymtapwvlrhnyyumvxtnlkubhkytegwyelrgaocmhlbhjwtgvotgyojiahbfpzdvmvcplgdsreaccviykegkuqsuzvbpvfmjcqynwbhpijtkfciripbchuwgpyxmfkwhauwzydognisumdlusmwbgujyuhkbtgivdgudkllxvdrhgedaqbdzvnxswhtpqemtmhywujvpoowxszzladkxshroonfgtrbfazcukzjzohyiixtkadkskbibonhhhlnhkrevqpwgxupftiswmcqydzbuolbvwqfijjdaybgxxvfrgxpuzfscewyvhaqfsxncgtehukeuijnqgckhhekoaijjkbqfzehhxlotxvnheaxnehumogaqrladmqinwrvvelrcielphjclsyzghzzymzdzrooqfllkxcohjbwskaffbfnigmitnluhzixhukttphaakzsvzxcaerklesgtgaahizoemhxbqadbzvyyucbbtlmzguvmuxtexkjltgokgrnholgkpjliwzkctfqncmsbwbmpjabstozhbhsqqfbpflryqkouwgwujijslnmebmoftixmnybsjutbghwcnsyyckspxfuarkhmsfahddapavsgcqlrkjpnthcsmyvfkcuchumnymcyhwglnrcxdrmwarrprmucoqgwlsjlgnlpjrayjcwmvikwbdntphveadclwnyccjunaumlzkxusksunfpdpkjpnnclcaqelktlefxdpwakgsgwavbphkgwzkidmyjxickokjuzgulootkoqlfxxnwyzeblekiopvezeyaksmbjhlzyzhvywtxwxahdlstanybrwberpfcxsbvtksshmrdlrmpegigtihnhltyaycxsfsmqlezxxciqqzvxkdssnhzyazyabwtjqfzblyaicjyuivtuzmnovomyqmytitcbybclzdtdosyyprtofgcdwqbmdbgnviovmrhnwarkurkkidaqlftivuwyvcosncozvvorxfdsyoehtexfjqphmlhhqvafyqgtlunkcscaiihcngjyyyfklnsbiuiimoexjthlnmlwwvajblkclrmwggaraizoxflgyvtmjekfbmrfxdhiutgbagscptrozewzbpnmvxuxjncgqlqmgxpgdhludekekgdovrarowqajuizfzolydudlhaqnkuzrznoqqfhmxjwtrxyslmspiwcrwsggofxntmejtnvtwtmnrnicbarlwveunkbbpapkovtkirdekptdedgfezscvwxigamwadipacziveohvjlanrhtsaxnwuyfumbxplopnpzktnsoydqnwygoaecwacbxoeudqkufztssikigpzwlxczzidvlfzkvfgyvqsdpnvhvhpewqahpeiopomavlkrqqroimtxzogxxvbtodcdjmsyceayrmrheixmuqjwgptdnwwbbaeknyjpcjpvwgdapcnlvyhbocfbydezgiktjvkneajciofzqsllssngvujvznvfyhajclwinflxtsxkkixecmlxgwvimsnmzovdbrnqxynsqkccschxouuxsrfejuqiknnnfbdebtwudbyyfhvtbrqujxasstdegssntvtxosrutpsyxptagmwrjzmdspiajaodxjcmbtiwkcwjrqkzcirnhftzwbcfdqkazmodhwzsawbrmntqwmffryfnzhuezffarvdzsdtszumniffgtklkjszkbtpcyudsritjnmeoisbsziystmecedmiwdkxznrrykclwicgadzboxthlzlqexybdiacyrtybwlzenhhtgihgeordzjiyhlbsngsezqhxbieppliytrezfxdehneqaiinoctnuclympnbcxbxofxvfcbmrfcrnngbrbrmdekpvzsxyuuobtjgvmumrzfhmlkdmdrrhbgeazbyvymyrxfpjbbdahmouwsjcjalnhqnitoftcdlakcjmdommabhzvsbgsmtbcjjyzqrbucbggnskbhycihbfzelsqhvvshtrxkstpuavjshkbgmlppqptejmnehfnawlmqebmexvzggcouoemevhkgtxmaeacalptrqfypbzwjbmfpqtwlbgtuggxkgbltqgmjlkaojyznlfcbaypbhkynqxxyyktpqgaesasebsrmzvpzueddpbqhypiwabnsjpwcsrgtlxfksulobotsrjbpbjodndxwvuynnegydnkyjvmmmggdrivurlxgqvdlrbyeigenvqlfnarzgafzicwbntidqlrhopnyytmtjxyxxsyfsdhcfdfuynaparyrimpghdardaocumiosrqzuyuslwjonihvwyedcewfgkhbzrrrikqeimztikjxsqtqpxutdqyjdhmebexlonsycrtmbdkwvdmkcidhzdsenfiolfbbutzymsloxvmtayfejlliofodkytxdvazozybulrtgdmidummfzwvemzrksqpprpesphmcagifusiogxvfvrliseumvkcmbiespturbewvwgmcdhjbawjubdhwplistmkkhebiixegfskjbtkcqvyrafpsqxkjlvvtbybkxhsdzdmbyyfqvdhxlypbvanjxkcyjfkgndjoixrgxyxsegspfhscjhlgsphdvrjkwvyesslsqkmuqelxogaxnlghdnkygwkdtijnawftgspzwbwkhwkwkqendqnloxohhyvkuaddsscrvybevnbhdhuixjuogkvnisxfvcipvkgsikxfxyodfkletfszsqnaimhdpptmbbemlbrlbiogsbnmjflbxabgnjleagqckwoxahibpyiiaxwjchkaknizyvdzevdorrlrawtqudauawfefpgpdqodmtcsofgiyrbzpurkzrgbpmiudqmihamvwqnkytuwmwvcsoosfwvuifrowdwdfkabbnoziixwgvazjotplolvuejqjivpsvsvkiustuozppyyfrpqidoehzurhricoaxyjuqcoebfvcdbvttdwhhfjdwqueukhuisqyugfxlabobxjxahgknpnlikscuzydrodnuikfjmwmlhjlpqveflppvhsriquzhyobizjrnhgyorlfhjjpubgriyitrfuyfjbnkkhxrpxigknqtxhpyngiorbfywfdfgsrtbomqnuxzipvhwkhjtpxkteirlnyufpnhfbzswytgnopjzwvuluegzoxkbvegktppvrjtpdbftqosolozgsihgftjbaslvhdsamnqrovlglfuzuwhmeovljemlyahidzirnajdvumjziitgrimhdyqjkcimlqpmahzbsfymthlbrhiipupuuiffmprxfjjisljkshylrjokqythvkbpuhwgwqfezrmtcvfwedhvoxghwbornqiixfovvwzunnppkunpzwmntuurvjklbttyyjvtfvpsiejvawkzsyootjfquqbvjuvheqcjnreyxntzkfaedoswzynvooqzlnirekctdgraumzgrzkvpftpfgktxdukqcbwmdqpkjrgysoptamifgzkokfnpzxhdyerewiqhzwfrmvmmjvupueegmrxnpfrpjkthtjouhuotraiavcssiwyupwigdbymlttgdjbmdpiwpqxnurfcpfzedjngkluxenejxhycwgzlyyaupfwgnxkqgzzsktqrjwcgdakzglmglnacuzihwtadszvfsnybjajobupjhcqtrsvnrevqzvvtwsyogysrzbgcxvlfzdaswvgpzbfayauutukbtcsugawfyhmxlmqjiyyjbgkzigvdahetmzpszlzztmxgyppinnuovgpemmhmtoifpxzqjzqelnklezuroohkwwqikzwfnencemtpnjtayfmcgivuycguaycmyarlfeqltlaiwtjwaxyghvahxjbzhflhfcvmjlxcyxmusvquuqabldikmljvswdaaymjlmnjlafgxxaunbxaegkstvpotuotucffouqawviuuiojlljrtvjpqbdjvtfqvkxkeombluxgenpqabjwwvlpwqatjfjepjqwxexkawsfjkxjlifjdsyziztteeywnqsmvrxxnpcyzbjkkrunjuputknaqnwegqqdhpawffwggftswpiijzcfjrfzhdfntyqcnqyuvudezwyynigwhkdqdisknzzgxrinkghhckleimcvukucwxuziomvonclfkyrtiyxumbdyfysrswnstpahdvxqxlxkjoftneobirznrthmswelneuqbsjbdgnoxsimyyngrmwkhdwzbcmpijfkbolgxywusggqetxvhtioyeqzheornwbqkmwjmtdezjvgeudnplcnsumbydsozuelibvvwazxmwfqqjefwiuoejpemisnczakavhywhxkfdayogfkqazujozxwtmasmnukuuidssjxshlbmvrowoznnwjikmdxbxhvspzmhklbrwcftwusktfzsqhcckzdkibezcqgmdkfzokukeouatvskfuopwubgvfgzxmlayqbnayxhmuhgpzsuvgmtcpaxvgyuujxtbygcydllzutrvlnqtbmwrmvosukmdhhfinjgtwtsqmllxzdtapptbkjveukkbrrjfcsayluqygbxhgqhwfdzsmvwifikyzvfbpfbbarbgsanzrwxybwsotryyzizzgeaxkcykvbsochpvfovhkoxefveegdfmiilumkghnyxphokmcitnyqtdoxjudrinzthnfnutnsiugvgldcydurgiqrcvkkijgrylgtevnppvkygpcgswzafstjnewypcponyjutwjltvlcmnigligqcbaphwnxafnpfwjyuulpryrdlajxkrpmtrdaptzpymfdkqdenruepnibptazlpngjtiymiomwvphnulalhfbvpekiemvvbbeukfiuvuqqlxfilitupwpeacogqkerlkoxpwrkticghkousiphegnhkbnanrszciytgqezaig");

    return 0;
}
