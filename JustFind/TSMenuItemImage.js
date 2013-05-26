/**
 * MenuItemImage 扩展类，用于响应图片点击事件
 */

var ts = ts || {};

cc.MenuItemImage.extend = cc.Class.extend;
var ts.TSMenuItemImage = cc.MenuItemImage.extend({	
	ctor:function () {
        this._super();
     //   this.init();
        this._visbleSize=cc.size(0,0);
    },
    getVisibleSize:function ()	{
    	if (cc.sizeEqualToSize(this._visbleSize,cc.size(0,0))){
    		this.updateVisibleSize();
    	}
    	return this._visbleSize;
    },
	updateVisibleSize:function ()	{		
		var size = this.getContentSize();
		var sizeVisible = cc.size(size.width*this.getScaleX(),size.height*this.getScaleY());
		var newWidth = sizeVisible.width*Math.cos(this.getRotationY()) + sizeVisible.height*Math.sin(this.getRotationX());
		var newHeight = sizeVisible.width*Math.sin(this.getRotationY()) + sizeVisible.height*Math.cos(this.getRotationX());
		this._visbleSize = cc.size(newWidth,newHeight);
		return this._visbleSize;
	}	
});
