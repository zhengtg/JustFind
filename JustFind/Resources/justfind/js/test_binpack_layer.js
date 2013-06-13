/**
 * 排列测试layer
 */

var TestBinPackController = cc.LayerGradient.extend({
    _Menu:null,

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
        this._Menu = cc.Menu.create();//item menu is where all the label goes, and the one gets scrolled
        
        var itemIndex = 10000;
        for (var i = 0, len = 5; i < len; i++) {
        	var index = 10000+ Math.round(Math.random()*10);
        	var path = "props/" + (index) + ".jpg";

        	var sprite = cc.Sprite.create(path); //cc.MenuItemImage.create(path, path, this.onMenuCallback, this);//cc.Sprite.create(path);
        	var scale = Math.random();
        	sprite.setScale(scale);
        	var rotation = Math.round(Math.random() * 360);
        	sprite.setRotation(rotation);
           
        	var size = ts.getNodeVisibleSize(sprite);
            cc.log("getNodeVisibleSize " + index + "," + size.width + "," + size.height + " scale: " + scale + " rotation:" + rotation);
            var packedRect = bin.Insert(size.width, size.height, heuristic);
 			if (packedRect.height > 0)
 			{
 			    if (packedRect.width != size.width) {
 			        sprite.setRotation(rotation + 90);
 			        cc.log("setRotation");
 			    }
 			    sprite.setPosition(cc.p(packedRect.width / 2, packedRect.height / 2));

 			    var point = ts.covertLBPointToCenter(cc.p(packedRect.x, packedRect.y), cc.size(packedRect.width, packedRect.height));
 	 			//cc.log("covertTLPointToCenter"+point.x + ","+point.y + ","+packedRect.x + ","+packedRect.y);
 			    var normalbkSprite = cc.LayerColor.create(cc.c4b(0, 0, 0, 128));
 			    var selectbkSprite = cc.LayerColor.create(cc.c4b(255, 0, 0, 128));
 			    normalbkSprite.setContentSize(cc.size(packedRect.width, packedRect.height));
 			    selectbkSprite.setContentSize(cc.size(packedRect.width, packedRect.height));

 			    var menuItem = cc.MenuItemSprite.create(normalbkSprite, selectbkSprite, this.onMenuCallback, this);
 			    menuItem.setContentSize(cc.size(packedRect.width, packedRect.height));
 			    menuItem.addChild(sprite, -1);
 			    menuItem.setPosition(point);		    

 			    this._Menu.addChild(menuItem, index);
			} 			
        }
        var visibleSize = cc.Director.getInstance().getWinSize();
        this._Menu.setContentSize(layerSize);
        this.addChild(this._Menu);
        this._Menu.setAnchorPoint(cc.p(0.5, 0.5));
        this._Menu.setPosition(cc.p(0,0));
       
    },
    onEnter:function(){
        this._Menu.setHandlerPriority(1);
    },
    onMenuCallback:function (sender) {
        var idx = sender.getZOrder();
        cc.log("onMenuCallback="+idx);
    }
});

