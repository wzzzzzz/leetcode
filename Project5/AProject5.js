


/****************************************第152题*********************************************/
/**
 * @param {number[]} nums
 * @return {number}
 */
// var maxProduct = function(nums) {
//     var len=nums.length;
//     if(len==1)
//         return nums[0];
//     var maxmin=new Array(len);
//     var last=new Array();
//     if(nums[len-1]>0){
//         last[0]=nums[len-1];
//         last[1]=-0;
//     }
//     else{
//         last[1]=nums[len-1];
//         last[0]=0;
//     }
//     console.log(last);
//     maxmin[len-1]=last;
//     var max=last[0];
//     var min=last[1];
//     for(var i=len-2;i>=0;i--){
//         var tmp=new Array();
//         if(nums[i]==0){
//             tmp[0]=0;
//             tmp[1]=-0;
//         }
//         else if(nums[i]>0){
//             tmp[0]=Math.max(maxmin[i+1][0]*nums[i],nums[i]);
//             tmp[1]=maxmin[i+1][1]*nums[i],nums[i];
//         }
//         else{
//             tmp[0]=Math.max(maxmin[i+1][1]*nums[i],nums[i]);
//             tmp[1]=Math.min(maxmin[i+1][0]*nums[i],nums[i]);
//         }
//         console.log(tmp);
//         maxmin[i]=tmp;
//         max=Math.max(max,tmp[0]);
//         min=Math.min(min,tmp[1]);
//     }
//     console.log(max+" "+min);
//     return max;
// };
// var nums=[-4,-3,-2];
// maxProduct(nums);



/****************************************第139题*********************************************/
// /**
//  * @param {string} s
//  * @param {string[]} wordDict
//  * @return {boolean}
//  */
// var word_Break = function(s, wordDict,flag) {
//     var len=wordDict.length;
//     var l=s.length;
//     for(var i=0;i<len;i++){
//         var t=wordDict[i].length;
//         if(flag[flag.length-l-t-1]==-1){
//             continue;
//         }     
//         if(s.substr(0,t)==wordDict[i]){
//             if(t==s.length || flag[flag.length-l-t-1]==1 || word_Break(s.substr(t),wordDict,flag)==true){
//                 flag[flag.length-l-1]=1;
//                 //console.log("t");
//                 return true;
//             }
//             else{
//                 flag[flag.length-l-t-1]=-1;
//             }
//         }
//     }
//     //console.log("f");
//     return false;
// };
// var wordBreak = function(s, wordDict) {
//     var l=s.length;
//     var flag=new Array(l);
//     for(var i=0;i<l;i++){
//         flag[i]=0;
//     }
//     var res=word_Break(s,wordDict,flag);
//     console.log(res);
//     return res;
// };

// var s="catsanddog";
// var d=["cats", "dog", "sand", "and", "cat"];
// wordBreak(s,d);



/****************************************第138题*********************************************/
// // Definition for a Node.
// function Node(val,next,random) {
//    this.val = val;
//    this.next = next;
//    this.random = random;
// };

// /**
//  * @param {Node} head
//  * @return {Node}
//  */
// var copyRandomList = function(head) {
//     var arr=new Array();
//     if(head==null){
//         return null;
//     }
//     while(head!=null){
//         arr.push(head);
//         var newnode=new Node(head.val);
//         arr.push(newnode);
//         head=head.next;
//     }
//     var len=arr.length;
//     for(var i=0;i<len-2;i+=2){
//         arr[i+1].next=arr[i+3];
//         var ind=arr.indexOf(arr[i].random);
//         if(ind==-1){
//             arr[i+1].random=null;
//         }
//         else{
//             arr[i+1].random=arr[ind+1];
//         }
//     }
//     arr[len-1].next=null;
//     var ind=arr.indexOf(arr[i].random);
//     if(ind==-1){
//         arr[i+1].random=null;
//     }
//     else{
//         arr[i+1].random=arr[ind+1];
//     }
//     console.log(arr[1]);
//     return arr[1];
// };
// var t0=new Node(0);
// var t1=new Node(1);
// // var t2=new Node(2);
// // var t3=new Node(3);
// // var t4=new Node(4);
// // var t5=new Node(5);
// // var t6=new Node(6);
// // var t7=new Node(7);
// // var t8=new Node(8);
// t0.next=t1;
// t1.next=null;
// t0.random=t1;
// t1.random=t1;
// copyRandomList(t0);



/****************************************第137题*********************************************/
// /**
//  * @param {number[]} nums
//  * @return {number}
//  */
// var singleNumber = function(nums) {
//     nums.sort();
//     console.log(nums);
//     if(nums==null){
//         return null;
//     }
//     var len=nums.length;
//     var res=nums[0];
//     if(len==1||res!=nums[1]){
//         return res;
//     }
//     for(var i=3;i<nums.length-1;i++){
//         if(nums[i]==nums[i+1]){
//             i+=2;
//         }
//         else{
//             res=nums[i];
//             console.log(res);
//             return res;
//         }
//     }
//     if(res==nums[0]){
//         res=nums[len-1];
//         console.log(res);
//         return res;
//     }
// };
// var nums=[0,4,0,3,4,0,4];
// singleNumber(nums);



/****************************************第134题*********************************************/
// /**
//  * @param {number[]} gas
//  * @param {number[]} cost
//  * @return {number}
//  */
// var canCompleteCircuit = function(gas, cost) {
//     var len=gas.length;
//     for(var i=0;i<len;i++){
//         if(gas[i]>=cost[i]){
//             var more=gas[i]-cost[i];
//             for(var j=i+1;j<len;j++){
//                 more=gas[j]+more-cost[j];
//                 //console.log("a"+j+" "+gas[j]+" "+more);
//                 if(more<0){
//                     break;
//                 }
//             }
//             if(j==len){
//                 for(j=0;j<i;j++){
//                     more=gas[j]+more-cost[j];
//                     //console.log("b"+j+" "+gas[j]+" "+more);
//                     if(more<0){
//                         break;
//                     }
//                 }
//             }
//             //console.log(i+" "+j);
//             if(j==i){
//                 //console.log("res"+i);
//                 return i;
//             }
//         }      
//     }
//     //console.log("res-1");
//     return -1;
// };
// var gas=[4,5,2,6,5,3];
// var cost=[3,2,7,3,2,9];
// canCompleteCircuit(gas,cost);



/****************************************第133题*********************************************/
// // Definition for a Node.
// function Node(val,neighbors) {
//    this.val = val;
//    this.neighbors = neighbors;
// };

// /**
//  * @param {Node} node
//  * @return {Node}
//  */
// var cloneGraph = function(node) {
//     if(node==null)
//         return null;
//     var res;
//     var stack=new Array();
//     var flag=new Array();
//     stack.push(node);
//     while(stack.length!=0){
//         var tmp=stack[0];
//         stack.shift();       
//         flag.push(tmp);
//         tmp.neighbors.forEach(ele => {
//             if(flag.indexOf(ele)==-1 && stack.indexOf(ele)==-1){
//                 stack.push(ele);
//             }
//         });
//         var newnode=new Node(tmp.val);
//         flag.push(newnode);
//         if(res==undefined)
//             res=newnode;
//     }
//     for(var i=0;i<flag.length-1;i+=2){
//         var tmp=flag[i];
//         var tmpres=flag[i+1];
//         tmpres.neighbors=new Array();
//         tmp.neighbors.forEach(ele => {
//             var ind=flag.indexOf(ele)+1;
//             tmpres.neighbors.push(flag[ind]);
//         });
//     }
//     node.val=9;
//     console.log(res);
//     console.log(res.neighbors[0]);
//     console.log(res.neighbors[1]);
//     console.log(res.neighbors[0].neighbors[0]);
//     console.log(res.neighbors[0].neighbors[1]);
//     console.log(res.neighbors[0].neighbors[1].neighbors[0]);
//     console.log(res.neighbors[0].neighbors[1].neighbors[1]);
//     return res;
// };
// var t0=new Node(0);
// var t1=new Node(1);
// var t2=new Node(2);
// var t3=new Node(3);
// // var t4=new Node(4);
// // var t5=new Node(5);
// // var t6=new Node(6);
// // var t7=new Node(7);
// // var t8=new Node(8);
// t0.neighbors=[t1,t3];
// t1.neighbors=[t0,t2];
// t2.neighbors=[t1,t3];
// t3.neighbors=[t0,t2];
// cloneGraph(t0);



/****************************************第131题*********************************************/
// /**
//  * @param {string} s
//  * @return {string[][]}
//  */
// var ispalindrome=function(s){
//     var len=s.length;
//     if(len==1)
//         return true;
//     for(var i=0;i<Math.floor(s.length/2);i++){
//         if(s[i]!=s[len-i-1])
//             return false;
//     }
//     //console.log(s+"是回文");
//     return true;
// };
// var partition = function(s) {
//     var res=new Array();
//     console.log(s);
//     if(s=="")
//         return res;
//     var len=s.length;
//     //for(var i=0;i<len;i++){
//         for(var j=0;j<len;j++){
//             var t=s.slice(0,j+1);
//             if(ispalindrome(t)==true){
//                 if(j<len-1){
//                     var tt=partition(s.slice(j+1));
//                     for(var k=0;k<tt.length;k++){
//                         res.push(new Array());
//                         res[res.length-1].push(t);
//                         res[res.length-1]=res[res.length-1].concat(tt[k]);
//                     }  
//                 }
//                 else{
//                     res.push(new Array());
//                     res[res.length-1].push(t);
//                 }
//             }
//         }
//     //} 
//     console.log(res);
//     return res;
// };

// var s="aabb";
// partition(s);



/****************************************第130题*********************************************/
// /**
//  * @param {character[][]} board
//  * @return {void} Do not return anything, modify board in-place instead.
//  */
// var changeconnected=function(b,i,j){
//     //上
//     if(i>0&&b[i-1][j]=="O"){
//         b[i-1][j]="C";
//         changeconnected(b,i-1,j);
//     }
//     //左
//     if(j>0&&b[i][j-1]=="O"){
//         b[i][j-1]="C";
//         changeconnected(b,i,j-1);
//     }
//     //下
//     if(i<b.length-1&&b[i+1][j]=="O"){
//         b[i+1][j]="C";
//         changeconnected(b,i+1,j);
//     }
//     //右
//     if(j<b[0].length-1&&b[i][j+1]=="O"){
//         b[i][j+1]="C";
//         changeconnected(b,i,j+1);
//     }
// };
// var solve = function(board) {
//     if(board==null||board[0]==null)
//         return;
//     var m=board.length;
//     var n=board[0].length;
//     if(m<3||n<3)
//         return;
//     //第一行
//     for(var j=0;j<n;j++){
//         if(board[0][j]=="O"){
//             board[0][j]="C";
//             changeconnected(board,0,j);
//         }
//     }
//     //最后一行
//     for(j=0;j<n;j++){
//         if(board[m-1][j]=="O"){
//             board[m-1][j]="C";
//             changeconnected(board,m-1,j);
//         }
//     }
//     //第一列
//     for(var j=1;j<m-1;j++){
//         if(board[j][0]=="O"){
//             board[j][0]="C";
//             changeconnected(board,j,0);
//         }
//     }
//     //最后一列
//     for(var j=1;j<m-1;j++){
//         if(board[j][n-1]=="O"){
//             board[j][n-1]="C";
//             changeconnected(board,j,n-1);
//         }
//     }

//     for(var i=0;i<m;i++){
//         for(var j=0;j<n;j++){
//             if(board[i][j]=="O"){
//                 board[i][j]="X";
//             }
//             if(board[i][j]=="C"){
//                 board[i][j]="O";
//             }
//             //console.log(board[i][j]);
//         }
//         //console.log(" ");
//     }
// };
// var b=[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]];
// solve(b);
// for(var i=0;i<b.length;i++){
//     for(var j=0;j<b[0].length;j++){
//         console.log(b[i][j]);
//     }
//     console.log(" ");
// }



/****************************************第127题*********************************************/
// /**
//  * @param {string} beginWord
//  * @param {string} endWord
//  * @param {string[]} wordList
//  * @return {number}
//  */
// var getdiff=function(word1,word2){
//     var len=word1.length;
//     var res=0;
//     if(word2=="")
//         return -1;
//     for(var i=0;i<len;i++){
//         if(word1[i]!=word2[i]){
//             res++;
//             if(res>=2)
//                 return -1;
//         }
//     }
//     return res;
// }
// var ladder_Length = function(wordList,ladder,ind,flag) {
//     var len=wordList.length;
//     var tmp=1+ladder[ind];
//     for(var i=0;i<len;i++){
//         if(ladder[i]==-1 || ladder[i]>tmp){
//             if((i<ind && flag[i][ind]==1)){
//                 ladder[i]=tmp;
//                 ladder_Length(wordList,ladder,i,flag);
//             }
//             if((i>ind && flag[ind][i]==1)){
//                 ladder[i]=tmp;
//                 ladder_Length(wordList,ladder,i,flag);
//             }
//         }
//     }
// };
// var ladderLength = function(beginWord, endWord, wordList) {
//     var ind=wordList.indexOf(endWord);
//     if(ind==-1||beginWord==endWord){
//         console.log("0");
//         return 0;
//     }
//     var len=wordList.length;
//     var ladder=new Array(len);
//     for(var i=0;i<len;i++){
//         ladder[i]=-1;
//     }
//     ladder[ind]=1;
//     var flag=new Array(len);
//     for(var i=0;i<len;i++){
//         flag[i]=new Array(len);
//         for(var j=0;j<=i;j++){
//             flag[i][j]=0;
//         }
//         for(var j=i+1;j<len;j++){
//             if(getdiff(wordList[i],wordList[j])==1){
//                 flag[i][j]=1;
//             }
//             else flag[i][j]=-1;
//         }
//     }
    
//     ladder_Length(wordList,ladder,ind,flag);

//     var res=len+1;
//     for(var i=0;i<len;i++){
//         if(getdiff(beginWord,wordList[i])==1){
//             res=Math.min(res,1+ladder[i]);
//         }
//     }
//     if(res==len+1){
//         return 0;
//     }
//     else {
//         console.log(res);
//         return res;
//     }
// };
// var b="sand";
// var e="acne";
// var w=["slit","bunk","wars","ping","viva","wynn","wows","irks","gang","pool","mock","fort","heel","send","ship","cols","alec","foal","nabs","gaze","giza","mays","dogs","karo","cums","jedi","webb","lend","mire","jose","catt","grow","toss","magi","leis","bead","kara","hoof","than","ires","baas","vein","kari","riga","oars","gags","thug","yawn","wive","view","germ","flab","july","tuck","rory","bean","feed","rhee","jeez","gobs","lath","desk","yoko","cute","zeus","thus","dims","link","dirt","mara","disc","limy","lewd","maud","duly","elsa","hart","rays","rues","camp","lack","okra","tome","math","plug","monk","orly","friz","hogs","yoda","poop","tick","plod","cloy","pees","imps","lead","pope","mall","frey","been","plea","poll","male","teak","soho","glob","bell","mary","hail","scan","yips","like","mull","kory","odor","byte","kaye","word","honk","asks","slid","hopi","toke","gore","flew","tins","mown","oise","hall","vega","sing","fool","boat","bobs","lain","soft","hard","rots","sees","apex","chan","told","woos","unit","scow","gilt","beef","jars","tyre","imus","neon","soap","dabs","rein","ovid","hose","husk","loll","asia","cope","tail","hazy","clad","lash","sags","moll","eddy","fuel","lift","flog","land","sigh","saks","sail","hook","visa","tier","maws","roeg","gila","eyes","noah","hypo","tore","eggs","rove","chap","room","wait","lurk","race","host","dada","lola","gabs","sobs","joel","keck","axed","mead","gust","laid","ends","oort","nose","peer","kept","abet","iran","mick","dead","hags","tens","gown","sick","odis","miro","bill","fawn","sumo","kilt","huge","ores","oran","flag","tost","seth","sift","poet","reds","pips","cape","togo","wale","limn","toll","ploy","inns","snag","hoes","jerk","flux","fido","zane","arab","gamy","raze","lank","hurt","rail","hind","hoot","dogy","away","pest","hoed","pose","lose","pole","alva","dino","kind","clan","dips","soup","veto","edna","damp","gush","amen","wits","pubs","fuzz","cash","pine","trod","gunk","nude","lost","rite","cory","walt","mica","cart","avow","wind","book","leon","life","bang","draw","leek","skis","dram","ripe","mine","urea","tiff","over","gale","weir","defy","norm","tull","whiz","gill","ward","crag","when","mill","firs","sans","flue","reid","ekes","jain","mutt","hems","laps","piss","pall","rowe","prey","cull","knew","size","wets","hurl","wont","suva","girt","prys","prow","warn","naps","gong","thru","livy","boar","sade","amok","vice","slat","emir","jade","karl","loyd","cerf","bess","loss","rums","lats","bode","subs","muss","maim","kits","thin","york","punt","gays","alpo","aids","drag","eras","mats","pyre","clot","step","oath","lout","wary","carp","hums","tang","pout","whip","fled","omar","such","kano","jake","stan","loop","fuss","mini","byrd","exit","fizz","lire","emil","prop","noes","awed","gift","soli","sale","gage","orin","slur","limp","saar","arks","mast","gnat","port","into","geed","pave","awls","cent","cunt","full","dint","hank","mate","coin","tars","scud","veer","coax","bops","uris","loom","shod","crib","lids","drys","fish","edit","dick","erna","else","hahs","alga","moho","wire","fora","tums","ruth","bets","duns","mold","mush","swop","ruby","bolt","nave","kite","ahem","brad","tern","nips","whew","bait","ooze","gino","yuck","drum","shoe","lobe","dusk","cult","paws","anew","dado","nook","half","lams","rich","cato","java","kemp","vain","fees","sham","auks","gish","fire","elam","salt","sour","loth","whit","yogi","shes","scam","yous","lucy","inez","geld","whig","thee","kelp","loaf","harm","tomb","ever","airs","page","laud","stun","paid","goop","cobs","judy","grab","doha","crew","item","fogs","tong","blip","vest","bran","wend","bawl","feel","jets","mixt","tell","dire","devi","milo","deng","yews","weak","mark","doug","fare","rigs","poke","hies","sian","suez","quip","kens","lass","zips","elva","brat","cosy","teri","hull","spun","russ","pupa","weed","pulp","main","grim","hone","cord","barf","olav","gaps","rote","wilt","lars","roll","balm","jana","give","eire","faun","suck","kegs","nita","weer","tush","spry","loge","nays","heir","dope","roar","peep","nags","ates","bane","seas","sign","fred","they","lien","kiev","fops","said","lawn","lind","miff","mass","trig","sins","furl","ruin","sent","cray","maya","clog","puns","silk","axis","grog","jots","dyer","mope","rand","vend","keen","chou","dose","rain","eats","sped","maui","evan","time","todd","skit","lief","sops","outs","moot","faze","biro","gook","fill","oval","skew","veil","born","slob","hyde","twin","eloy","beat","ergs","sure","kobe","eggo","hens","jive","flax","mons","dunk","yest","begs","dial","lodz","burp","pile","much","dock","rene","sago","racy","have","yalu","glow","move","peps","hods","kins","salk","hand","cons","dare","myra","sega","type","mari","pelt","hula","gulf","jugs","flay","fest","spat","toms","zeno","taps","deny","swag","afro","baud","jabs","smut","egos","lara","toes","song","fray","luis","brut","olen","mere","ruff","slum","glad","buds","silt","rued","gelt","hive","teem","ides","sink","ands","wisp","omen","lyre","yuks","curb","loam","darn","liar","pugs","pane","carl","sang","scar","zeds","claw","berg","hits","mile","lite","khan","erik","slug","loon","dena","ruse","talk","tusk","gaol","tads","beds","sock","howe","gave","snob","ahab","part","meir","jell","stir","tels","spit","hash","omit","jinx","lyra","puck","laue","beep","eros","owed","cede","brew","slue","mitt","jest","lynx","wads","gena","dank","volt","gray","pony","veld","bask","fens","argo","work","taxi","afar","boon","lube","pass","lazy","mist","blot","mach","poky","rams","sits","rend","dome","pray","duck","hers","lure","keep","gory","chat","runt","jams","lays","posy","bats","hoff","rock","keri","raul","yves","lama","ramp","vote","jody","pock","gist","sass","iago","coos","rank","lowe","vows","koch","taco","jinn","juno","rape","band","aces","goal","huck","lila","tuft","swan","blab","leda","gems","hide","tack","porn","scum","frat","plum","duds","shad","arms","pare","chin","gain","knee","foot","line","dove","vera","jays","fund","reno","skid","boys","corn","gwyn","sash","weld","ruiz","dior","jess","leaf","pars","cote","zing","scat","nice","dart","only","owls","hike","trey","whys","ding","klan","ross","barb","ants","lean","dopy","hock","tour","grip","aldo","whim","prom","rear","dins","duff","dell","loch","lava","sung","yank","thar","curl","venn","blow","pomp","heat","trap","dali","nets","seen","gash","twig","dads","emmy","rhea","navy","haws","mite","bows","alas","ives","play","soon","doll","chum","ajar","foam","call","puke","kris","wily","came","ales","reef","raid","diet","prod","prut","loot","soar","coed","celt","seam","dray","lump","jags","nods","sole","kink","peso","howl","cost","tsar","uric","sore","woes","sewn","sake","cask","caps","burl","tame","bulk","neva","from","meet","webs","spar","fuck","buoy","wept","west","dual","pica","sold","seed","gads","riff","neck","deed","rudy","drop","vale","flit","romp","peak","jape","jews","fain","dens","hugo","elba","mink","town","clam","feud","fern","dung","newt","mime","deem","inti","gigs","sosa","lope","lard","cara","smug","lego","flex","doth","paar","moon","wren","tale","kant","eels","muck","toga","zens","lops","duet","coil","gall","teal","glib","muir","ails","boer","them","rake","conn","neat","frog","trip","coma","must","mono","lira","craw","sled","wear","toby","reel","hips","nate","pump","mont","died","moss","lair","jibe","oils","pied","hobs","cads","haze","muse","cogs","figs","cues","roes","whet","boru","cozy","amos","tans","news","hake","cots","boas","tutu","wavy","pipe","typo","albs","boom","dyke","wail","woke","ware","rita","fail","slab","owes","jane","rack","hell","lags","mend","mask","hume","wane","acne","team","holy","runs","exes","dole","trim","zola","trek","puma","wacs","veep","yaps","sums","lush","tubs","most","witt","bong","rule","hear","awry","sots","nils","bash","gasp","inch","pens","fies","juts","pate","vine","zulu","this","bare","veal","josh","reek","ours","cowl","club","farm","teat","coat","dish","fore","weft","exam","vlad","floe","beak","lane","ella","warp","goth","ming","pits","rent","tito","wish","amps","says","hawk","ways","punk","nark","cagy","east","paul","bose","solo","teed","text","hews","snip","lips","emit","orgy","icon","tuna","soul","kurd","clod","calk","aunt","bake","copy","acid","duse","kiln","spec","fans","bani","irma","pads","batu","logo","pack","oder","atop","funk","gide","bede","bibs","taut","guns","dana","puff","lyme","flat","lake","june","sets","gull","hops","earn","clip","fell","kama","seal","diaz","cite","chew","cuba","bury","yard","bank","byes","apia","cree","nosh","judo","walk","tape","taro","boot","cods","lade","cong","deft","slim","jeri","rile","park","aeon","fact","slow","goff","cane","earp","tart","does","acts","hope","cant","buts","shin","dude","ergo","mode","gene","lept","chen","beta","eden","pang","saab","fang","whir","cove","perk","fads","rugs","herb","putt","nous","vane","corm","stay","bids","vela","roof","isms","sics","gone","swum","wiry","cram","rink","pert","heap","sikh","dais","cell","peel","nuke","buss","rasp","none","slut","bent","dams","serb","dork","bays","kale","cora","wake","welt","rind","trot","sloe","pity","rout","eves","fats","furs","pogo","beth","hued","edam","iamb","glee","lute","keel","airy","easy","tire","rube","bogy","sine","chop","rood","elbe","mike","garb","jill","gaul","chit","dons","bars","ride","beck","toad","make","head","suds","pike","snot","swat","peed","same","gaza","lent","gait","gael","elks","hang","nerf","rosy","shut","glop","pain","dion","deaf","hero","doer","wost","wage","wash","pats","narc","ions","dice","quay","vied","eons","case","pour","urns","reva","rags","aden","bone","rang","aura","iraq","toot","rome","hals","megs","pond","john","yeps","pawl","warm","bird","tint","jowl","gibe","come","hold","pail","wipe","bike","rips","eery","kent","hims","inks","fink","mott","ices","macy","serf","keys","tarp","cops","sods","feet","tear","benz","buys","colo","boil","sews","enos","watt","pull","brag","cork","save","mint","feat","jamb","rubs","roxy","toys","nosy","yowl","tamp","lobs","foul","doom","sown","pigs","hemp","fame","boor","cube","tops","loco","lads","eyre","alta","aged","flop","pram","lesa","sawn","plow","aral","load","lied","pled","boob","bert","rows","zits","rick","hint","dido","fist","marc","wuss","node","smog","nora","shim","glut","bale","perl","what","tort","meek","brie","bind","cake","psst","dour","jove","tree","chip","stud","thou","mobs","sows","opts","diva","perm","wise","cuds","sols","alan","mild","pure","gail","wins","offs","nile","yelp","minn","tors","tran","homy","sadr","erse","nero","scab","finn","mich","turd","then","poem","noun","oxus","brow","door","saws","eben","wart","wand","rosa","left","lina","cabs","rapt","olin","suet","kalb","mans","dawn","riel","temp","chug","peal","drew","null","hath","many","took","fond","gate","sate","leak","zany","vans","mart","hess","home","long","dirk","bile","lace","moog","axes","zone","fork","duct","rico","rife","deep","tiny","hugh","bilk","waft","swig","pans","with","kern","busy","film","lulu","king","lord","veda","tray","legs","soot","ells","wasp","hunt","earl","ouch","diem","yell","pegs","blvd","polk","soda","zorn","liza","slop","week","kill","rusk","eric","sump","haul","rims","crop","blob","face","bins","read","care","pele","ritz","beau","golf","drip","dike","stab","jibs","hove","junk","hoax","tats","fief","quad","peat","ream","hats","root","flak","grit","clap","pugh","bosh","lock","mute","crow","iced","lisa","bela","fems","oxes","vies","gybe","huff","bull","cuss","sunk","pups","fobs","turf","sect","atom","debt","sane","writ","anon","mayo","aria","seer","thor","brim","gawk","jack","jazz","menu","yolk","surf","libs","lets","bans","toil","open","aced","poor","mess","wham","fran","gina","dote","love","mood","pale","reps","ines","shot","alar","twit","site","dill","yoga","sear","vamp","abel","lieu","cuff","orbs","rose","tank","gape","guam","adar","vole","your","dean","dear","hebe","crab","hump","mole","vase","rode","dash","sera","balk","lela","inca","gaea","bush","loud","pies","aide","blew","mien","side","kerr","ring","tess","prep","rant","lugs","hobo","joke","odds","yule","aida","true","pone","lode","nona","weep","coda","elmo","skim","wink","bras","pier","bung","pets","tabs","ryan","jock","body","sofa","joey","zion","mace","kick","vile","leno","bali","fart","that","redo","ills","jogs","pent","drub","slaw","tide","lena","seep","gyps","wave","amid","fear","ties","flan","wimp","kali","shun","crap","sage","rune","logs","cain","digs","abut","obit","paps","rids","fair","hack","huns","road","caws","curt","jute","fisk","fowl","duty","holt","miss","rude","vito","baal","ural","mann","mind","belt","clem","last","musk","roam","abed","days","bore","fuze","fall","pict","dump","dies","fiat","vent","pork","eyed","docs","rive","spas","rope","ariz","tout","game","jump","blur","anti","lisp","turn","sand","food","moos","hoop","saul","arch","fury","rise","diss","hubs","burs","grid","ilks","suns","flea","soil","lung","want","nola","fins","thud","kidd","juan","heps","nape","rash","burt","bump","tots","brit","mums","bole","shah","tees","skip","limb","umps","ache","arcs","raft","halo","luce","bahs","leta","conk","duos","siva","went","peek","sulk","reap","free","dubs","lang","toto","hasp","ball","rats","nair","myst","wang","snug","nash","laos","ante","opal","tina","pore","bite","haas","myth","yugo","foci","dent","bade","pear","mods","auto","shop","etch","lyly","curs","aron","slew","tyro","sack","wade","clio","gyro","butt","icky","char","itch","halt","gals","yang","tend","pact","bees","suit","puny","hows","nina","brno","oops","lick","sons","kilo","bust","nome","mona","dull","join","hour","papa","stag","bern","wove","lull","slip","laze","roil","alto","bath","buck","alma","anus","evil","dumb","oreo","rare","near","cure","isis","hill","kyle","pace","comb","nits","flip","clop","mort","thea","wall","kiel","judd","coop","dave","very","amie","blah","flub","talc","bold","fogy","idea","prof","horn","shoo","aped","pins","helm","wees","beer","womb","clue","alba","aloe","fine","bard","limo","shaw","pint","swim","dust","indy","hale","cats","troy","wens","luke","vern","deli","both","brig","daub","sara","sued","bier","noel","olga","dupe","look","pisa","knox","murk","dame","matt","gold","jame","toge","luck","peck","tass","calf","pill","wore","wadi","thur","parr","maul","tzar","ones","lees","dark","fake","bast","zoom","here","moro","wine","bums","cows","jean","palm","fume","plop","help","tuba","leap","cans","back","avid","lice","lust","polo","dory","stew","kate","rama","coke","bled","mugs","ajax","arts","drug","pena","cody","hole","sean","deck","guts","kong","bate","pitt","como","lyle","siam","rook","baby","jigs","bret","bark","lori","reba","sups","made","buzz","gnaw","alps","clay","post","viol","dina","card","lana","doff","yups","tons","live","kids","pair","yawl","name","oven","sirs","gyms","prig","down","leos","noon","nibs","cook","safe","cobb","raja","awes","sari","nerd","fold","lots","pete","deal","bias","zeal","girl","rage","cool","gout","whey","soak","thaw","bear","wing","nagy","well","oink","sven","kurt","etna","held","wood","high","feta","twee","ford","cave","knot","tory","ibis","yaks","vets","foxy","sank","cone","pius","tall","seem","wool","flap","gird","lore","coot","mewl","sere","real","puts","sell","nuts","foil","lilt","saga","heft","dyed","goat","spew","daze","frye","adds","glen","tojo","pixy","gobi","stop","tile","hiss","shed","hahn","baku","ahas","sill","swap","also","carr","manx","lime","debs","moat","eked","bola","pods","coon","lacy","tube","minx","buff","pres","clew","gaff","flee","burn","whom","cola","fret","purl","wick","wigs","donn","guys","toni","oxen","wite","vial","spam","huts","vats","lima","core","eula","thad","peon","erie","oats","boyd","cued","olaf","tams","secs","urey","wile","penn","bred","rill","vary","sues","mail","feds","aves","code","beam","reed","neil","hark","pols","gris","gods","mesa","test","coup","heed","dora","hied","tune","doze","pews","oaks","bloc","tips","maid","goof","four","woof","silo","bray","zest","kiss","yong","file","hilt","iris","tuns","lily","ears","pant","jury","taft","data","gild","pick","kook","colt","bohr","anal","asps","babe","bach","mash","biko","bowl","huey","jilt","goes","guff","bend","nike","tami","gosh","tike","gees","urge","path","bony","jude","lynn","lois","teas","dunn","elul","bonn","moms","bugs","slay","yeah","loan","hulk","lows","damn","nell","jung","avis","mane","waco","loin","knob","tyke","anna","hire","luau","tidy","nuns","pots","quid","exec","hans","hera","hush","shag","scot","moan","wald","ursa","lorn","hunk","loft","yore","alum","mows","slog","emma","spud","rice","worn","erma","need","bags","lark","kirk","pooh","dyes","area","dime","luvs","foch","refs","cast","alit","tugs","even","role","toed","caph","nigh","sony","bide","robs","folk","daft","past","blue","flaw","sana","fits","barr","riot","dots","lamp","cock","fibs","harp","tent","hate","mali","togs","gear","tues","bass","pros","numb","emus","hare","fate","wife","mean","pink","dune","ares","dine","oily","tony","czar","spay","push","glum","till","moth","glue","dive","scad","pops","woks","andy","leah","cusp","hair","alex","vibe","bulb","boll","firm","joys","tara","cole","levy","owen","chow","rump","jail","lapp","beet","slap","kith","more","maps","bond","hick","opus","rust","wist","shat","phil","snow","lott","lora","cary","mote","rift","oust","klee","goad","pith","heep","lupe","ivan","mimi","bald","fuse","cuts","lens","leer","eyry","know","razz","tare","pals","geek","greg","teen","clef","wags","weal","each","haft","nova","waif","rate","katy","yale","dale","leas","axum","quiz","pawn","fend","capt","laws","city","chad","coal","nail","zaps","sort","loci","less","spur","note","foes","fags","gulp","snap","bogs","wrap","dane","melt","ease","felt","shea","calm","star","swam","aery","year","plan","odin","curd","mira","mops","shit","davy","apes","inky","hues","lome","bits","vila","show","best","mice","gins","next","roan","ymir","mars","oman","wild","heal","plus","erin","rave","robe","fast","hutu","aver","jodi","alms","yams","zero","revs","wean","chic","self","jeep","jobs","waxy","duel","seek","spot","raps","pimp","adan","slam","tool","morn","futz","ewes","errs","knit","rung","kans","muff","huhs","tows","lest","meal","azov","gnus","agar","sips","sway","otis","tone","tate","epic","trio","tics","fade","lear","owns","robt","weds","five","lyon","terr","arno","mama","grey","disk","sept","sire","bart","saps","whoa","turk","stow","pyle","joni","zinc","negs","task","leif","ribs","malt","nine","bunt","grin","dona","nope","hams","some","molt","smit","sacs","joan","slav","lady","base","heck","list","take","herd","will","nubs","burg","hugs","peru","coif","zoos","nick","idol","levi","grub","roth","adam","elma","tags","tote","yaws","cali","mete","lula","cubs","prim","luna","jolt","span","pita","dodo","puss","deer","term","dolt","goon","gary","yarn","aims","just","rena","tine","cyst","meld","loki","wong","were","hung","maze","arid","cars","wolf","marx","faye","eave","raga","flow","neal","lone","anne","cage","tied","tilt","soto","opel","date","buns","dorm","kane","akin","ewer","drab","thai","jeer","grad","berm","rods","saki","grus","vast","late","lint","mule","risk","labs","snit","gala","find","spin","ired","slot","oafs","lies","mews","wino","milk","bout","onus","tram","jaws","peas","cleo","seat","gums","cold","vang","dewy","hood","rush","mack","yuan","odes","boos","jami","mare","plot","swab","borg","hays","form","mesh","mani","fife","good","gram","lion","myna","moor","skin","posh","burr","rime","done","ruts","pays","stem","ting","arty","slag","iron","ayes","stub","oral","gets","chid","yens","snub","ages","wide","bail","verb","lamb","bomb","army","yoke","gels","tits","bork","mils","nary","barn","hype","odom","avon","hewn","rios","cams","tact","boss","oleo","duke","eris","gwen","elms","deon","sims","quit","nest","font","dues","yeas","zeta","bevy","gent","torn","cups","worm","baum","axon","purr","vise","grew","govs","meat","chef","rest","lame"
// ladderLength(b,e,w);



/****************************************第120题*********************************************/
// /**
//  * @param {number[][]} triangle
//  * @return {number}
//  */
// var minimumTotal = function(triangle) {
//     var res=0;
//     if(triangle.length==0)
//         return res;
//     var min=new Array(triangle[triangle.length-1].length)
//     var minn=new Array();
//     min[0]=triangle[0][0];
//     // for(var i=1;i<triangle[triangle.length-1].length;i++)
//     //     min[i]=0;
//     for(var i=1;i<triangle.length;i++){
//         for(var k=0;k<min.length;k++)
//             minn[k]=min[k];
//         for(var j=0;j<triangle[i].length;j++){
//             var tmp=triangle[i][j];   
//             //最左边
//             if(j==0){
//                 min[j]=minn[j]+tmp;
//             } 
//             else if(j==triangle[i].length-1){
//                 min[j]=minn[j-1]+tmp;
//             } 
//             else{
//                 min[j]=Math.min(minn[j-1]+tmp,minn[j]+tmp);
//             }
//         }
//         console.log(min);
//     }
//     var res=min[0];
//     for(var i=0;i<min.length;i++){
//         if(res>min[i])
//             res=min[i];
//     }
//     console.log(res);
//     return res;
// };

// var t=new Array();
// t[0]=[-1];
// t[1]=[3,2];
// t[2]=[-3,1,-1];
// //t[3]=[4,1,8,3];
// minimumTotal(t);



/****************************************第116题*********************************************/
// // Definition for a Node.
// function Node(val,left,right,next) {
//    this.val = val;
//    this.left = left;
//    this.right = right;
//    this.next = next;
// };
// /**
//  * @param {Node} root
//  * @return {Node}
//  */
// var connect = function(root) {
//     	var s = new Array();
//         var res =new Array();
//         if (root == null) {
// 			return null;
// 		}
// 		s.push(root);
// 		var t =new Node(1);
// 		s.push(t);
// 		while (s.length!=0) {
// 			var tmp = s.shift();
// 			//cout << tmp << endl;
// 			if (tmp == t) {
//                 for(var i=0;i<res.length-1;i++){
//                     res[i].next=res[i+1];
//                 }
//                 res[i].next=null;
//                 if (s.length==0)
//                     break;                
// 				res.length=0;
// 				s.push(t);
// 				continue;
// 			}
// 			res.push(tmp);
// 			if (tmp.left)
// 				s.push(tmp.left);
// 			if (tmp.right)
// 				s.push(tmp.right);
// 		}

//         return root;
// };
// var t0=new Node(0);
// var t1=new Node(1);
// var t2=new Node(2);
// var t3=new Node(3);
// var t4=new Node(4);
// var t5=new Node(5);
// var t6=new Node(6);
// var t7=new Node(7);
// var t8=new Node(8);
// t0.left = t1;
// t0.right = t2;
// t1.left = t3;
// t1.right = t4;
// t2.left = t5;
// t2.right = t6;
// t4.left = t7;
// t4.right = t8;
// connect(t0);



/****************************************第114题*********************************************/
// //Definition for a binary tree node.
// function TreeNode(val) {
//     this.val = val;
//    this.left = this.right = null;
// }
// /**
//  * @param {TreeNode} root
//  * @return {void} Do not return anything, modify root in-place instead.
//  */
// var flatten = function(root) {
//     if(root==null)
//         return null;
//     var arr=new Array();
//     arr.push(root);
//     arr.pop();
//     if(root.right)
//         arr.push(root.right);
//     if(root.left)
//         arr.push(root.left);
//     root.left=null;
//     root.right=null;
//     var res=root;
//     while(arr.length!=0){
//         var tmp=arr[arr.length-1];
//         res.right=tmp;
//         res.left=null;
//         res=res.right;
//         arr.pop();
//         if(tmp.right)
//             arr.push(tmp.right);
//         if(tmp.left)
//             arr.push(tmp.left);
//     }
//     // while(root){
//     //     console.log(root.val);
//     //     root=root.right;
//     // }
// };
// var t0=new TreeNode(0);
// var t1=new TreeNode(1);
// var t2=new TreeNode(2);
// var t3=new TreeNode(3);
// var t4=new TreeNode(4);
// var t5=new TreeNode(5);
// var t6=new TreeNode(6);
// var t7=new TreeNode(7);
// var t8=new TreeNode(8);
// t0.left = t1;
// t0.right = t2;
// t1.left = t3;
// t1.right = t4;
// t2.left = t5;
// t2.right = t6;
// t4.left = t7;
// t4.right = t8;
// flatten(t0);



/****************************************第113题*********************************************/
// //Definition for a binary tree node.
// function TreeNode(val) {
//     this.val = val;
//     this.left = this.right = null;
// }
 
// /**
//  * @param {TreeNode} root
//  * @param {number} sum
//  * @return {number[][]}
//  */

// var pathSum = function(root, sum) {
//     //这个是用来遍历的栈
//     var arr=new Array();
//     //这个是用来保存路径上的节点的
//     var path=new Array();
//     //保存结果
//     var res=new Array();
//     if(root==null)
//         return res;
//     arr.push(root);
//     path.push(root);
//     var tmp;
//     res.push(new Array());
//     while(arr.length!=0){
//         tmp=arr[arr.length-1];
//         res[res.length-1].push(tmp.val);
//         add+=tmp.val;
//         arr.pop();
//         if(tmp.right){
//             arr.push(tmp.right);
//             path.push(tmp.right);
//         }
//         if(tmp.left){
//             arr.push(tmp.left);
//             path.push(tmp.left);
//         }  
//         if(!(tmp.left||tmp.right)){
//             var add=0;
//             for(var i=0;i<res[res.length-1].length;i++){
//                 add+=res[res.length-1][i];
//             }
            
//             if(add==sum){
//                 console.log(add);
//                 if(arr.length!=0){
//                     res.push(new Array());
//                     for(var i=0;i<res[res.length-2].length;i++){
//                         res[res.length-1][i]=res[res.length-2][i];
//                     }
//                 }
//                 else break;
//             }
//             while(arr[arr.length-1]!=path[path.length-1]){
//                 path.pop();
//                 if(res[res.length-1].length!=0)
//                     res[res.length-1].pop();
//             }
//         }
//         console.log(res);
//     }
//     if(res[res.length-1].length==0)
//         res.length--;
//     console.log(res);
//     return res;
// };

// var t0=new TreeNode(5);
// var t1=new TreeNode(4);
// var t2=new TreeNode(8);
// var t3=new TreeNode(11);
// var t4=new TreeNode(13);
// var t5=new TreeNode(4);
// var t6=new TreeNode(7);
// var t7=new TreeNode(2);
// var t8=new TreeNode(5);
// var t9=new TreeNode(1);
// // t0.left = t1;
// // t0.right = t2;
// // t1.left = t3;
// // t2.left = t4;
// // t2.right = t5;
// // t3.left = t6;
// // t3.right = t7;
// // t5.left = t8;
// // t5.right = t9;
// pathSum(t0,5);



/****************************************第一百零九题*********************************************/
// //Definition for singly-linked list.
// function ListNode(val) {
//     this.val = val;
//     this.next = null;
// }

//  //Definition for a binary tree node.
// function TreeNode(val) {
//     this.val = val;
//     this.left = this.right = null;
// }
 
// /**
//  * @param {ListNode} head
//  * @return {TreeNode}
//  */
// var createTreeNode=function(nums){
//     var len=nums.length;
//     if(len==1)
//         return new TreeNode(nums[0]);
//     var ind=Math.floor(len/2);
//     //console.log(ind);
//     var r=new TreeNode(nums[ind]);
//     if(ind!=0){
//         r.left=createTreeNode(nums.slice(0,ind));
//     }
//     if(ind!=len-1){
//         r.right=createTreeNode(nums.slice(ind+1));
//     }
//     return r;
// }

// var sortedListToBST = function(head) {
//     if(head==null)
//         return null;
//     var num=[];
//     var len=0;
//     while(head!=null){
//         num[len++]=head.val;
//         head=head.next;
//     }
//     //console.log(num);

//     var root = createTreeNode(num);
//     return root;
// };

// var LevelOrder = function(root) {
//     var s = new Array();
//     var res =new Array();
//     if (root == null) {
//         return res;
//     }
//     res[0]=new Array();
//     s.push(root);
//     var t = TreeNode(1);
//     s.push(t);
//     while (s.length!=0) {
//         var tmp = s.shift();
//         //cout << tmp << endl;
//         if (tmp == t) {
//             if (s.length==0)
//                 break;
//             res[res.length]=new Array();
//             s.push(t);
//             continue;
//         }
//         res[res.length - 1].push(tmp.val);
//         if (tmp.left)
//             s.push(tmp.left);
//         if (tmp.right)
//             s.push(tmp.right);
//     }

//     for (var i = 0; i < res.length; i++) {
//         for (var j = 0; j < res[i].length; j++) {
//             console.log( res[i][j]);
//         }
//         console.log("\n");
//     }

//     return res;
// }

// var l0=new ListNode(-10);
// var l1=new ListNode(-3);
// var l2=new ListNode(0);
// var l3=new ListNode(1);
// var l4=new ListNode(5);
// var l5=new ListNode(9);
// l0.next=l1;
// l1.next=l2;
// l2.next=l3;
// l3.next=l4;
// l4.next=l5;

// var t = sortedListToBST(l0);
// console.log(t);
// LevelOrder(t);



/****************************************第一百零五 一百零六题*********************************************/
// //Definition for a binary tree node.
// function TreeNode(val) {
//    this.val = val;
//     this.left = this.right = null;
// }
// /**
//  * @param {number[]} preorder
//  * @param {number[]} inorder
//  * @return {TreeNode}
//  */
// var buildTree = function(inorder, postorder) {    
//     var len=inorder.length;
//     if(len==0)
//         return null;
//     var val=postorder[len-1];
//     var root=new TreeNode(val);
//     if(inorder.length==1)
//         return root;
//     var ind=inorder.indexOf(val);
//     var rightin=inorder.slice(ind+1);
//     var rightpost=postorder.slice(ind,len-1);
//     root.right=buildTree(rightin,rightpost);
   
//     var leftin=inorder.slice(0,ind);
//     var leftpost=postorder.slice(0,ind);
//     root.left=buildTree(leftin,leftpost);

//     return root;
// };
// // var buildTree = function(preorder, inorder) {    
// //     if(preorder.length==0)
// //         return new TreeNode(undefined);
// //     var root=new TreeNode(preorder[0]);
// //     if(preorder.length==1)
// //         return root;
// //     var ind=inorder.indexOf(preorder[0]);
// //     var leftin=inorder.slice(0,ind);
// //     var leftpre=preorder.slice(1,ind+1);
// //     root.left=buildTree(leftpre,leftin);
// //     var rightin=inorder.slice(ind+1);
// //     var rightpre=preorder.slice(ind+1);
// //     root.right=buildTree(rightpre,rightin);

// //     return root;
// // };
// var LevelOrder = function(root) {
//     var s = new Array();
//     var res =new Array();
//     if (root == null) {
//         return res;
//     }
//     res[0]=new Array();
//     s.push(root);
//     var t = TreeNode(1);
//     s.push(t);
//     while (s.length!=0) {
//         var tmp = s.shift();
//         //cout << tmp << endl;
//         if (tmp == t) {
//             if (s.length==0)
//                 break;
//             res[res.length]=new Array();
//             s.push(t);
//             continue;
//         }
//         res[res.length - 1].push(tmp.val);
//         if (tmp.left)
//             s.push(tmp.left);
//         if (tmp.right)
//             s.push(tmp.right);
//     }

//     for (var i = 0; i < res.length; i++) {
//         for (var j = 0; j < res[i].length; j++) {
//             console.log( res[i][j]);
//         }
//         console.log("\n");
//     }

//     return res;    
// };
// var post=[4,2,8,6,7,5,3,1];
// var ino=[4,2,1,3,8,6,5,7];
// var t=buildTree(ino,post);
// //测试一下输出
// LevelOrder(t);



/****************************************第一百零三题*********************************************/
//  //Definition for a binary tree node.
//  function TreeNode(val) {
//      this.val = val;
//      this.left = this.right = null;
//  }
 
// /**
//  * @param {TreeNode} root
//  * @return {number[][]}
//  */
// var zigzagLevelOrder = function(root) {
// 		var s = new Array();
//         var res =new Array();
//         if (root == null) {
// 			return res;
// 		}
// 		res[0]=new Array();
// 		s.push(root);
// 		var t = TreeNode(1);
// 		s.push(t);
// 		while (s.length!=0) {
// 			var tmp = s.shift();
// 			//cout << tmp << endl;
// 			if (tmp == t) {
// 				//如果需要，反转
// 				if(res.length%2==0){
// 					res[res.length-1].reverse();
// 				}
// 				if (s.length==0)
// 					break;
// 				res[res.length]=new Array();
// 				s.push(t);
// 				continue;
// 			}
// 			res[res.length - 1].push(tmp.val);
// 			if (tmp.left)
// 				s.push(tmp.left);
// 			if (tmp.right)
// 				s.push(tmp.right);
// 		}

// 		for (var i = 0; i < res.length; i++) {
// 			for (var j = 0; j < res[i].length; j++) {
// 				console.log( res[i][j]);
// 			}
// 			console.log("\n");
// 		}

// 		return res;    
// };

// var t0=new TreeNode(0);
// var t1=new TreeNode(1);
// var t2=new TreeNode(2);
// var t3=new TreeNode(3);
// var t4=new TreeNode(4);
// var t5=new TreeNode(5);
// var t6=new TreeNode(6);
// var t7=new TreeNode(7);
// var t8=new TreeNode(8);
// t0.left = t1;
// t0.right = t2;
// t1.left = t3;
// t1.right = t4;
// t2.left = t5;
// t2.right = t6;
// t4.left = t7;
// t4.right = t8;
// zigzagLevelOrder(t0);