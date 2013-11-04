#include "ai09.h"

void ai09::NormalPlayDef ( void )
{
	MarkManager();
	
	for (map<int,int>::const_iterator i=markMap.begin(); i!=markMap.end(); ++i) {
		int opp = i->second;
		int own = i->first;
		
		if (oneTouchDetector[own].IsArriving()) {
			WaitForPass(own, false);
		}
		else
		{
		
			if (opp==-1) {
				OwnRobot[own].face(Vec2(-side*3025, 0));
				ERRTSetObstacles(own, 0, 1, 1, 0, 0, 0);
				if (own==dmf) {
					ERRTNavigate2Point(dmf, Vec2(side*300, -1600), 0, 100, &VELOCITY_PROFILE_MAMOOLI);
				}
				else if (own==lmf) {
					ERRTNavigate2Point(lmf, Vec2(0, -1600), 0, 100, &VELOCITY_PROFILE_MAMOOLI);
				}
				else if (own==rmf) {
					ERRTNavigate2Point(rmf, Vec2(0, 1600), 0, 100, &VELOCITY_PROFILE_MAMOOLI);
				}
			}
			else {
				OwnRobot[own].face(ball.Position);
				Mark2Goal(own,opp,100);
			}
		}
	}
	
	float shootAngle = NormalizeAngle( 180+calculateOpenAngleToGoal(ball.Position, attack).X);
	tech_circle(attack, shootAngle, 15, 0, 1, 0, 0, 1);
}