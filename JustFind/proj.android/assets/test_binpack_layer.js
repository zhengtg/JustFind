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
        for (var i = 0, len = 50; i < len; i++) {
        	var index = 10000+ Math.round(Math.random()*10);
        	var path = "props/" + (index) + ".png";
        	
        	var menuItem = cc.Sprite.create(path);//cc.MenuItemImage.create(path, path, this.onMenuCallback, this);
        	menuItem.setScale(Math.random());
        	//menuItem.setRotation(Math.round(Math.random()*360));
        	
           // this._itemMenu.addChild(menuItem, index);
            var size = ts.getNodeVisibleSize(menuItem);
            cc.log("getNodeVisibleSize " + index + "," + size.width + "," + size.height);
 			var packedRect = bin.Insert(size.width, size.height, heuristic);
 			if (packedRect.height > 0)
			{
 				var point = cc.p(packedRect.x,packedRect.y);
 	 			menuItem.setAnchorPoint(cc.p(0,0));
 	 		//	var point = ts.covertTLPointToCenter(cc.p(packedRect.x,packedRect.y),size);
 	 			cc.log("covertTLPointToCenter"+point.x + ","+point.y + ","+packedRect.x + ","+packedRect.y);
 	 			 menuItem.setPosition(point);
 	 			this.addChild(menuItem, index);
			} 			
        }

//        this._itemMenu.setContentSize(cc.size(layerSize.width,layerSize.height));
//        this.addChild(this._itemMenu);
//        this._itemMenu.setAnchorPoint(cc.p(0,0));
//        this._itemMenu.setPositionX(0);
       
    },
    onEnter:function(){
    	//this._itemMenu.setHandlerPriority(1);
    },
    onMenuCallback:function (sender) {
        var idx = sender.getZOrder();
        cc.log("onMenuCallback=%d",idx);
    }
});

