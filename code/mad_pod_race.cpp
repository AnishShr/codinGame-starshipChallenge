#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <math.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int compute_distance(int x1, int y1, int x2, int y2)
{
    int distance_squared = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    return (int)(sqrt(distance_squared));
}

int main()
{

    // game loop
    while (1) {
        int x;
        int y;
        int next_checkpoint_x; // x position of the next check point
        int next_checkpoint_y; // y position of the next check point
        int next_checkpoint_dist; // distance to the next checkpoint
        int next_checkpoint_angle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> next_checkpoint_x >> next_checkpoint_y >> next_checkpoint_dist >> next_checkpoint_angle; cin.ignore();
        int opponent_x;
        int opponent_y;
        cin >> opponent_x >> opponent_y; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        int thrust = 100;
        bool is_boost_available = true;
        bool boost = false;

        if (next_checkpoint_angle > 90 || next_checkpoint_angle < -90) 
        {
            thrust = 0;
        }        
        else
        {
            if (is_boost_available && abs(next_checkpoint_angle) <= 10 && next_checkpoint_dist > 7000) 
            {
                boost = true; 
            }
            else if (compute_distance(x, y, next_checkpoint_x, next_checkpoint_y) < 600)
            {
                boost = false;
                thrust = 25;

                if (compute_distance(x, y, next_checkpoint_x, next_checkpoint_y) < 100)
                {
                    thrust = 8;
                }
            }
            else if (compute_distance(x, y, opponent_x, opponent_y) < 50)
            {
                boost = false;
                thrust = 5;
            }
        }       

        if (!boost)
        {
            cout << next_checkpoint_x << " " << next_checkpoint_y << " " << thrust << endl;
        } 
        else
        {
            cout << next_checkpoint_x << " " << next_checkpoint_y << " " << "BOOST" << endl;
        }          

        if (boost)
        {
            is_boost_available = false;
        }
    }
}