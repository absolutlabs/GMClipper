// Boost Software License - Version 1.0 - August 17th, 2003
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Objective-C Wrapper by Richard Moore (me@ricmoo.com), 2014.
//
// Original Clipper library by Angus Johnson (see clipper.hpp for more details).
//

#import <Foundation/Foundation.h>

#import "GMClipper.h"

typedef enum Orientation {
    OrientationClockwise,
    OrientationAnticlockwise
} Orientation;


/**
 *  GMPoint
 *
 *    A simple point whose components are integers.
 */
@interface GMPoint: NSObject

@property (nonatomic, assign) NSInteger x;
@property (nonatomic, assign) NSInteger y;

+ (id)pointWithX: (NSInteger)x y: (NSInteger)y;

@end


@interface GMPolygon : NSObject

/**
 *  The area of the polygon.
 */
@property (nonatomic, readonly) double area;

/**
 *  The orientation of the polygon, ie. clockwise or anti-clockwise winding.
 */
@property (nonatomic, readonly) Orientation orientation;


/**
 *  The list of points of the polygon's path.
 */
@property (nonatomic, readonly) NSArray *points;

/**
 *  The number of points in the polygon's path.
 */
@property (nonatomic, readonly) NSUInteger count;


/**
 *  @returns new polygon
 */
+ (id)polygon;


/**
 *  Removes self-intersections (Polygons with non-contiguous duplicate vertices will be split into two)
 *
 *  See: http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/SimplifyPolygon.htm
 */
+ (NSArray*)simplifyPolygon: (GMPolygon*)polygons;

/**
 *  @see simplifyPolygon::
 */
+ (NSArray*)simplifyPolygon: (GMPolygon*)polygon polygonFillType: (PolygonFillType)polygonFillType;

/**
 *  @see simplifyPolygon::
 */
+ (NSArray*)simplifyPolygons: (NSArray*)polygons;

/**
 *  @see simplifyPolygon::
 */
+ (NSArray*)simplifyPolygons: (NSArray*)polygons polygonFillType: (PolygonFillType)polygonFillType;


/**
 *  Removes vertices that:
 *    - join co-linear edges (or "near" co-linear)
 *    - are within the specified distance of an adjacent vertex (default: 1.415f)
 *    - are within the specified distance of a semi-adjacent vertex together with their out-lying vertices
 *
 *  See: http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/CleanPolygon.htm
 */
+ (GMPolygon*)cleanPolygon: (GMPolygon*)polygon;

/**
 *  @see cleanPolygon::
 */
+ (GMPolygon*)cleanPolygon: (GMPolygon*)polygon distance: (double)distance;

/**
 *  @see cleanPolygon::
 */
+ (NSArray*)cleanPolygons: (NSArray*)polygons;

/**
 *  @see cleanPolygon::
 */
+ (NSArray*)cleanPolygons: (NSArray*)polygons distance: (double)distance;


/**
 *  Test whether a point lies inside the polygon.
 */
- (BOOL)containsPoint: (GMPoint*)point;

/**
 *  Test whether a point (x, y) lies inside the polygon.
 */
- (BOOL)containsPointX: (NSInteger)x y: (NSInteger)y;


/**
 *  Add a point to the end of the polygon's path.
 */
- (void)addPoint: (GMPoint*)point;

/**
 *  Add a point (x, y) to the end of the polygon's path.
 */
- (void)addPointX: (NSInteger)x y: (NSInteger)y;


/**
 *  @see cleanPolygon:
 */
- (void)cleanPolygon;

/**
 *  @see cleanPolygon:
 */
- (void)cleanPolygonDistance: (double)distance;


/**
 *  Reverse the polygon's path (changing its @name orientation).
 */
- (void)reverse;


/**
 *  Clear the polygon's path.
 */
- (void)clear;

@end
