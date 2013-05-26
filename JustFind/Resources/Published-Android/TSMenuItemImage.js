/**
 * MenuItemImage 扩展类，用于响应图片点击事件
 */

var ts = ts || {};

var ts.TSMenuItemImage = cc.MenuItemImage.extend({	
	ctor:function () {
        this._super();
     //   this.init();
        this._visbleRect=cc.rect(0,0,0,0);
        this._visbleSize=cc.size(0,0);
    },
    getVisibleRect:function ()	{
    	if (cc.rectEqualToRec(this._visbleRect,cc.rect(0,0,0,0))){
    		this.updateVisibleRect();
    	}
    	return this._visbleRect;
    },
    getVisibleSize:function ()	{
    	if (cc.sizeEqualToSize(this._visbleSize,cc.size(0,0))){
    		this.updateVisibleSize();
    	}
    	return this._visbleSize;
    },
	updateVisibleRect:function ()	{		
		var size = this.getContentSize();
		var sizeVisible = cc.size(size.width*this.getScaleX(),size.height*this.getScaleY());
		var newWidth = sizeVisible.width*Math.cos(this.getRotationY()) + sizeVisible.height*Math.sin(this.getRotationX());
		var newHeight = sizeVisible.width*Math.sin(this.getRotationY()) + sizeVisible.height*Math.cos(this.getRotationX());
		this._visbleRect = cc.rect(this.getPositionX(),this.getPositionY(),newWidth,newHeight);
		return this._visbleRect;
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