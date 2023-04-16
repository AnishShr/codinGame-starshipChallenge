# codinGame-starshipChallenge

## How the code works

### compute_distance
- This function computes the euclidean distance between any two points (x1, y1) and (x2, y2), when run in the following order:   
    `compute_distance(x1, y1, x2, y2)`

### The main program
```
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
```

This is the input which provides the current x and y coordinates of the star-ship, along with the x and y coordinates of the next checkpoint, and for the opposition as well.   

With these data, the trajectory of the path can be planned, and can be traversed in any provided environment.   

Here, a simple logic is implemented for the star ship to traverse along any simulated environemnt that is provided by **codinGame**.   

Firstly, if the star ship is supposed to make a complete u-turn (-90 to 90 degrees), then the thrust is set to zero so it buys itself some time, after which again it is driven by some thrust(acceleration.)   
```
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
```
Also, if the distance between the star-ship and the next checkpoint is significantly high, then the available boost is used which accelerates the star-ship in a very high velocity. However, this is available only once. So once used, it cannot be used again. This is the reason to introduce the boolean variables, `is_boost_available` and `boost`.   

In this process, the distance between the starship and the next checkpoint needs to be constantly examined. In cse the distance is within a range, the thrust needs to be decreased, in order to slow down the star-ship so that it does not take a longer route while making a turn around the checkpoint (time-saving). Furthermore, at times because of high thrust, the star-ship tends to rotate around a checkpoint constantly. To mitigate such actions, if the distance between the starship and the checkpoint is too low, the thrust is set to **8** which is very low. This enables the starship to slowly head towards teh checkpoint so that it can complete that checkpoint and move forward towards next checkpoint.

Also, collision with other star-ship needs to be taken into account. For doing so, when the star-ship and the opponent's star-ship is very close, the thrust is lowered to **5** so that the star-ship slows down and tries to avoid the collision. However, slight collision might be advantageous as well, so it is not completely to zero, and the distance threshold is also set accordingly.

