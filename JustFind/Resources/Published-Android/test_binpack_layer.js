/**
 * ≈≈¡–≤‚ ‘layer
 */
require("TSMenuItemImage.js");

var TestBinPackController = cc.LayerGradient.extend({
    _itemMenu:null,
    _beginPos:0,
    isMouseDown:false,

    ctor:function() {
        this._super();
        // this.init( cc.c4b(0,0,0,255), cc.c4b(98,99,117,255), cc.p(-1,-1));
        this.init( cc.c4b(0,0,0,255), cc.c4b(0x46,0x82,0xB4,255));

        // globals
        director = cc.Director.getInstance();
        winSize = director.getWinSize();
      //  var bin = new binpack.MaxRectsBinPack() ;
      //  bin.Init(winSize.width, winSize.height*2);
        // add close menu
      //  var closeItem = cc.MenuItemImage.create(s_pathClose, s_pathClose, this.onCloseCallback, this);
      //  closeItem.setPosition(winSize.width - 30, winSize.height - 30);
        
        var heuristic = 2;//pinpack.MaxRectsBinPack::RectBestAreaFit; // This can be changed individually even for each rectangle packed.

        // add menu items for tests
        this._itemMenu = cc.Menu.create();//item menu is where all the label goes, and the one gets scrolled
        var itemIndex = 10000;
        for (var i = 0, len = 10; i < len; i++) {
        	var path = "path" + itemIndex + i;
        	var menuItem = cc.MenuItemImage.create(path, path, this.onMenuCallback, this);
            this._itemMenu.addChild(menuItem, i + itemIndex);
            var vRect = menuItem.getVisibleRect()
 		//	var packedRect = bin.Insert(vRect.size.width, vRect.size.height, heuristic);
            
            menuItem.setPosition(packedRect.x+vRect.size.width*i, packedRect.y);
        }

        this._itemMenu.setContentSize(cc.size(winSize.width,winSize.height*2));
       // this._itemMenu.setPosition(curPos);
        this.addChild(this._itemMenu);
        this.addChild(menu, 1);

        // 'browser' can use touches or mouse.
        // The benefit of using 'touches' in a browser, is that it works both with mouse events or touches events
        if( 'touches' in sys.capabilities )
            this.setTouchEnabled(true);
    },
    onEnter:function(){
        this._super();
        var pos = this._itemMenu.getPosition();
        this._itemMenu.setPosition(pos.x, TestBinPackController.YOffset);
    },
    onMenuCallback:function (sender) {
    	TestBinPackController.YOffset = this._itemMenu.getPosition().y;
        var idx = sender.getZOrder() - 10000;
    },
    onCloseCallback:function () {
        history.go(-1);
    },
   
    onTouchesMoved:function (touches, event) {
        var delta = touches[0].getDelta();
        return true;
    }
});

TestBinPackController.YOffset = 0;