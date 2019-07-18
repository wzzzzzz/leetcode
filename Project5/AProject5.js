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