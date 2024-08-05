# Rubik's Cube 

This project involves rendering a dynamic Rubik's cube, providing an interactive 3D experience where users can manipulate the cube through keyboard and mouse inputs. The implementation includes building the cube, creating appropriate data structures, handling rotations, and enabling user interactions.

# About

The dynamic Rubik's cube project includes the following features:

1. **Cube Rendering**:
   - A 3D Rubik's cube rendered using `AddShape(Cube, -1, TRIANGLES)`.
   - The cube consists of smaller cubes, each uniquely positioned to form the classic Rubik's cube structure.
   - Each face of the cube has a unique color, applied via a custom Fragment Shader.

2. **User Interactions**:
   - **Keyboard Controls**:
     - Arrow keys to rotate the entire cube around the x and y axes.
     - Specific keys to rotate individual faces of the cube:
       - 'R' for right face rotation.
       - 'L' for left face rotation.
       - 'U' for upper face rotation.
       - 'D' for down face rotation.
       - 'B' for back face rotation.
       - 'F' for front face rotation.
       - ' ' to toggle rotation direction (clockwise/counterclockwise).
       - 'Z' to halve the rotation angle.
       - 'A' to double the rotation angle.
   - **Mouse Controls**:
     - Left button drag to rotate the cube around global axes.
     - Right button drag to move the camera view.
     - Scroll to zoom in and out.

3. **Data Structures**:
   - Efficient management of cube transformations using the `Movable` data structure.
   - Index-based tracking of smaller cubes to handle face rotations accurately.

4. **Advanced Features**:
   - Support for different cube sizes: 2x2, 4x4, and 5x5 configurations.

# How To Use

1. Use the arrow keys to rotate the cube around the x and y axes.
2. Press the defined keys to rotate specific faces of the cube and modify rotation angles.
3. Use the mouse to rotate the entire cube and move the camera.
4. Observe the cube's behavior and verify correct rotations.

# Features

1. Interactive 3D rendering of a Rubik's cube.
2. Comprehensive keyboard and mouse controls for manipulating the cube.
3. Unique colors for each face of the cube.
4. Efficient data structures for managing cube transformations.
5. Advanced support for various cube sizes and solving algorithms.

# Screenshots
<img style="max-width:100px; width:40%"  src="https://github.com/GalEden99/RubiksCube/blob/master/RubiksCube.png" alt="rubiksCube" >
