/**
 * 排列测试layer
 */

require("ts_utils.js");

var TestBinPackController = cc.LayerGradient.extend({
    _itemMenu:null,

    ctor:function(layerSize) {
        this._super();
        // this.init( cc.c4b(0,0,0,255), cc.c4b(98,99,117,255), cc.p(-1,-1));
        this.init( cc.c4b(0,0,0,255), cc.c4b(0x46,0x82,0xB4,255));
        this.setContentSize(layerSize);
        // globals
        var bin = new binpack.MaxRectsBinPack() ;
        bin.Init(layerSize.width, layerSize.height);
     
        var heuristic = 2;//pinpack.MaxRectsBinPack::RectBestAreaFit; // This can be changed individually even for each rectangle packed.

        // add menu items for tests
        this._itemMenu = cc.Menu.create();//item menu is where all the label goes, and the one gets scrolled
        
        var itemIndex = 10000;
        for (var i = 0, len = 10; i < len; i++) {
        	var path = "props/" + (itemIndex + i) + ".png";
        	var menuItem = cc.MenuItemImage.create(path, path, this.onMenuCallback, this);
            this._itemMenu.addChild(menuItem, i + itemIndex);
            var size = ts.getNodeVisibleSize(menuItem);
            cc.log("pic=%d getNodeVisibleSize %f,%f",i + itemIndex,size.width,size.height);
 			var packedRect = bin.Insert(size.width, size.height, heuristic);
 			var point = ts.covertTLPointToCenter(cc.p(packedRect.x,packedRect.y),size);
 			cc.log("covertTLPointToCenter %f,%f,%d,%d",point.x,point.y,packedRect.x,packedRect.y);
 			 menuItem.setPosition(point);
        }

        this._itemMenu.setContentSize(cc.size(layerSize.width,layerSize.height));
        this.addChild(this._itemMenu);
        this._itemMenu.setAnchorPoint(cc.p(0,0.5));
        this._itemMenu.setPositionX(0);
       
    },
    onEnter:function(){
    	this._itemMenu.setHandlerPriority(1);
    },
    onMenuCallback:function (sender) {
        var idx = sender.getZOrder();
        cc.log("onMenuCallback=%d",idx);
    }
});

