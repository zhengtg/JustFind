/*
 * ts 公共接口函数
 */

var ts = ts || {};

ts.d2r = function (angle) {
    return angle * 0.01745329252;  //PI / 180
};

ts.r2d = function (angle) {
    return angle * 57.29577951; //PI * 180
};

//根据NODE获取节点的外接矩形
ts.getNodeVisibleSize = function (node) {	
	if (node && node.isVisible()){
		var size = node.getContentSize();
		//cc.log("node.getContentSize =" + size.width + "," + size.height);
		var sizeVisible = cc.size(size.width * node.getScaleX(), size.height * node.getScaleY());
		var newWidth = Math.abs(sizeVisible.width * Math.cos(ts.d2r(node.getRotationY()))) + Math.abs(sizeVisible.height * Math.sin(ts.d2r(node.getRotationX())));
		var newHeight = Math.abs(sizeVisible.width * Math.sin(ts.d2r(node.getRotationY()))) + Math.abs(sizeVisible.height * Math.cos(ts.d2r(node.getRotationX())));
		return cc.size(newWidth,newHeight);
	}
	return cc.size(0,0);
};

//将左下角坐标转换成中心坐标
ts.covertLBPointToCenter = function(topLeftPoint,size){
	return cc.p(topLeftPoint.x+size.width/2,topLeftPoint.y+size.height/2);
};

