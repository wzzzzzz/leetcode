


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
// var getdiff=function(word1,word2,len){
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
// //这个思路，js的函数，参数里如果有引用类型就就要当心，尤其是考虑想要递归调用的时候，后面的递归调用修改掉引用类型会导致所有的这个值都受影响！
// var getlength=function(beginWord,endWord,wordList){
//     if(beginWord==endWord)
//         return 0;
//     var res=-1;
//     var t=-1;
//     for(var i=0;i<wordList.length;i++){
//         if(wordList[i]!="" && getdiff(beginWord,wordList[i])==1){
//             var tmp=new Array();
//             //这里创建一个新数组

//             t=getlength(wordList[i],endWord,tmp);
//         }
//         if(t!=-1)
//             res=t<res-1?t+1:res;
//     }
//     return res;
// }
// var ladderLength = function(beginWord, endWord, wordList) {
//     if(wordList.indexOf(endWord)!=-1)
//         return 0;
//     var res=0;

// };
// var b="hit";
// var e="cog";
// var w=["hot","dot","dog","lot","log","cog"];
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