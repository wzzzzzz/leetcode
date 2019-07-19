//Definition for a binary tree node.
function TreeNode(val) {
   this.val = val;
    this.left = this.right = null;
}
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(inorder, postorder) {    
    var len=inorder.length;
    if(len==0)
        return null;
    var val=postorder[len-1];
    var root=new TreeNode(val);
    if(inorder.length==1)
        return root;
    var ind=inorder.indexOf(val);
    var rightin=inorder.slice(ind+1);
    var rightpost=postorder.slice(ind,len-1);
    root.right=buildTree(rightin,rightpost);
   
    var leftin=inorder.slice(0,ind);
    var leftpost=postorder.slice(0,ind);
    root.left=buildTree(leftin,leftpost);

    return root;
};
// var buildTree = function(preorder, inorder) {    
//     if(preorder.length==0)
//         return new TreeNode(undefined);
//     var root=new TreeNode(preorder[0]);
//     if(preorder.length==1)
//         return root;
//     var ind=inorder.indexOf(preorder[0]);
//     var leftin=inorder.slice(0,ind);
//     var leftpre=preorder.slice(1,ind+1);
//     root.left=buildTree(leftpre,leftin);
//     var rightin=inorder.slice(ind+1);
//     var rightpre=preorder.slice(ind+1);
//     root.right=buildTree(rightpre,rightin);

//     return root;
// };
var zigzagLevelOrder = function(root) {
    var s = new Array();
    var res =new Array();
    if (root == null) {
        return res;
    }
    res[0]=new Array();
    s.push(root);
    var t = TreeNode(1);
    s.push(t);
    while (s.length!=0) {
        var tmp = s.shift();
        //cout << tmp << endl;
        if (tmp == t) {
            if (s.length==0)
                break;
            res[res.length]=new Array();
            s.push(t);
            continue;
        }
        res[res.length - 1].push(tmp.val);
        if (tmp.left)
            s.push(tmp.left);
        if (tmp.right)
            s.push(tmp.right);
    }

    for (var i = 0; i < res.length; i++) {
        for (var j = 0; j < res[i].length; j++) {
            console.log( res[i][j]);
        }
        console.log("\n");
    }

    return res;    
};
var post=[4,2,8,6,7,5,3,1];
var ino=[4,2,1,3,8,6,5,7];
var t=buildTree(ino,post);
zigzagLevelOrder(t);



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