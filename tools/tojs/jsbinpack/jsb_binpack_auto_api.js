/**
 * @module binpack
 */
var binpack = binpack || {};

/**
 * @class DisjointRectCollection
 */
binpack.DisjointRectCollection = {

/**
 * @method Disjoint
 * @return A value converted from C/C++ "bool"
 * @param {Rect}
 */
Disjoint : function () {},

/**
 * @method Add
 * @return A value converted from C/C++ "bool"
 * @param {Rect}
 */
Add : function () {},

/**
 * @method Clear
 */
Clear : function () {},

/**
 * @method Disjoint2
 * @return A value converted from C/C++ "bool"
 * @param {Rect}
 * @param {Rect}
 */
Disjoint2 : function () {},

};

/**
 * @class GuillotineBinPack
 */
binpack.GuillotineBinPack = {

/**
 * @method GetUsedRectangles
 * @return A value converted from C/C++ "std::vector<Rect, std::allocator<Rect> >"
 */
GetUsedRectangles : function () {},

/**
 * @method MergeFreeList
 */
MergeFreeList : function () {},

/**
 * @method Occupancy
 * @return A value converted from C/C++ "float"
 */
Occupancy : function () {},

/**
 * @method GetFreeRectangles
 * @return A value converted from C/C++ "std::vector<Rect, std::allocator<Rect> >"
 */
GetFreeRectangles : function () {},

/**
 * @method Init
 * @param {int}
 * @param {int}
 */
Init : function () {},

};

/**
 * @class MaxRectsBinPack
 */
binpack.MaxRectsBinPack = {

/**
 * @method Init
 * @param {int}
 * @param {int}
 */
Init : function () {},

/**
 * @method Occupancy
 * @return A value converted from C/C++ "float"
 */
Occupancy : function () {},

};

/**
 * @class ShelfBinPack
 */
binpack.ShelfBinPack = {

/**
 * @method Insert
 * @return A value converted from C/C++ "Rect"
 * @param {int}
 * @param {int}
 * @param {ShelfBinPack::ShelfChoiceHeuristic}
 */
Insert : function () {},

/**
 * @method Init
 * @param {int}
 * @param {int}
 * @param {bool}
 */
Init : function () {},

/**
 * @method Occupancy
 * @return A value converted from C/C++ "float"
 */
Occupancy : function () {},

};

/**
 * @class ShelfNextFitBinPack
 */
binpack.ShelfNextFitBinPack = {

/**
 * @method Insert
 * @return A value converted from C/C++ "Node"
 * @param {int}
 * @param {int}
 */
Insert : function () {},

/**
 * @method Init
 * @param {int}
 * @param {int}
 */
Init : function () {},

/**
 * @method Occupancy
 * @return A value converted from C/C++ "float"
 */
Occupancy : function () {},

};

/**
 * @class SkylineBinPack
 */
binpack.SkylineBinPack = {

/**
 * @method Init
 * @param {int}
 * @param {int}
 * @param {bool}
 */
Init : function () {},

/**
 * @method Occupancy
 * @return A value converted from C/C++ "float"
 */
Occupancy : function () {},

};
