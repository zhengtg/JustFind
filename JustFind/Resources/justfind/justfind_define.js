﻿// Autogenerated main.js file

require('jsb_cocos2d_constants.js');
require('jsb_cocos2d.js');
require('jsb_cocos2d_extension.js');
require('jsb_opengl_constants.js');
require('jsb_opengl.js');
require('jsb_cocosbuilder.js');
require('jsb_sys.js');

//require("jsb.js");

// Load justfind files
var justfind_files = [
    // Resources definitions
    //'tests_resources-jsb.js',

    // Load binpack file
    'js/jsb_binpack_auto_api.js',

    // base class
    'js/ts_utils.js',
	'js/binpack_test.js',
	'js/test_binpack_layer.js',
];

//whether to obfuscate the code
for (var i = 0; i < justfind_files.length; i++) {
    var name = "" + justfind_files[i];
    require(name);
}