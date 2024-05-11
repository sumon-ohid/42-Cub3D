/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:45:20 by msumon            #+#    #+#             */
/*   Updated: 2024/05/11 11:45:45 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

// Constants
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FOV_ANGLE M_PI / 3  // 60 degrees in radians
#define NUM_RAYS 200

// Player struct
typedef struct {
    float x;
    float y;
    float angle;
    float fov;
} Player;

void drawWallSlice(float wallHeight);
// Map array
int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Function to cast a ray
void castRay(float rayAngle, Player player) {
    float x = player.x;
    float y = player.y;
    float dx = cos(rayAngle);
    float dy = sin(rayAngle);

    // Increment x and y until we hit a wall
    int i = 0;
    while (map[(int)y][(int)x] == 0) {
        x += dx * 0.1;
        y += dy * 0.1;
        i++;
        if (i > 400) break;  // Prevent infinite loops
    }

    float distance = sqrt(pow(x - player.x, 2) + pow(y - player.y, 2));
    float wallHeight = 300 / distance;

    // Draw wall slice
    drawWallSlice(wallHeight);
}

// Function to draw a wall slice
void drawWallSlice(float wallHeight) {
    for (int j = 0; j < wallHeight; j++) {
        int yPosition = 300 - wallHeight / 2 + j;
        printf("Draw wall slice at y = %d\n", yPosition);
    }
}

// Function to perform raycasting
void raycast(Player player) {
    float sliceWidth = (float)SCREEN_WIDTH / NUM_RAYS;
    float angleStep = player.fov / NUM_RAYS;

    // Iterate through rays
    for (int i = 0; i < NUM_RAYS; i++) {
        float rayAngle = player.angle - (player.fov / 2) + i * angleStep;
        castRay(rayAngle, player);
    }
}

// Main function
int main() {
    // Initialize player
    Player player = {3.5, 3.5, 0, FOV_ANGLE};

    // Perform raycasting
    raycast(player);

    return 0;
}
