/*
 *  Tiny Wings Remake
 *  http://github.com/haqu/tiny-wings
 *
 *  Created by Sergey Tikhonov http://haqu.net
 *  Released under the MIT License
 *
 */

#import <Foundation/Foundation.h>
#import "cocos2d.h"
#import "Box2D.h"

#define kPerfectTakeOffVelocityY 2.0f

@class GameLayer;
class HeroContactListener;

@interface Hero : CCNode {
	GameLayer *_game;
	CCSprite *_sprite;
	b2Body *_body;
	float _radius;
	BOOL _awake;
	BOOL _flying;
	BOOL _diving;
	HeroContactListener *_contactListener;
	int _nPerfectSlides;
    BOOL _frenzy;
    CCParticleSystem *_frenzyParticle;
}
@property (nonatomic, retain) GameLayer *game;
@property (nonatomic, retain) CCSprite *sprite;
@property (readonly) BOOL awake;
@property (nonatomic) BOOL diving;

+ (id) heroWithGame:(GameLayer*)game;
- (id) initWithGame:(GameLayer*)game;

- (void) reset;
- (void) sleep;
- (void) wake;
- (void) updatePhysics;
- (void) updateNode;

- (void) landed;
- (void) tookOff;
- (void) hit;

- (void) startFrenzy;
- (void) stopFrenzy;

@end
