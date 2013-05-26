/*
 * ts 公共接口函数
 */

var ts = ts || {};

//根据NODE获取节点的外接矩形
ts.getNodeVisibleSize = function (node) {	
	if (node && node.isVisible()){
		var size = node.getContentSize();
		//cc.log("node.getContentSize = %f,%f",size.width,size.height);
		var sizeVisible = cc.size(size.width*node.getScaleX(),size.height*node.getScaleY());
		var newWidth = sizeVisible.width*Math.cos(node.getRotationY()) + sizeVisible.height*Math.sin(node.getRotationX());
		var newHeight = sizeVisible.width*Math.sin(node.getRotationY()) + sizeVisible.height*Math.cos(node.getRotationX());
		return cc.size(newWidth,newHeight);
	}
	return cc.size(0,0);
};

//将左上角坐标转换成中心坐标
ts.covertTLPointToCenter = function(topLeftPoint,size){
	return cc.p(topLeftPoint.x+size.width/2,topLeftPoint.y-size.height/2);
};

