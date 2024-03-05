#pragma once   //maybe should be static class
#include "display.h"
#include "game.h"
#include <iostream>


	void mouse_callback(GLFWwindow* window,int button, int action, int mods)
	{	
		if(action == GLFW_PRESS )
		{
			Game *scn = (Game*)glfwGetWindowUserPointer(window);
			double x2,y2;
			glfwGetCursorPos(window,&x2,&y2);
			scn->Picking((int)x2,(int)y2);
		}
	}
	
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		float sensitivity = 0.5f;
		Game *scn = (Game*)glfwGetWindowUserPointer(window);
		scn->MoveCamera(0, scn->zTranslate, yoffset*sensitivity);
	}
	
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Game *scn = (Game*)glfwGetWindowUserPointer(window);

		if(action == GLFW_PRESS || action == GLFW_REPEAT)
		{
			switch (key)
			{
				case GLFW_KEY_ESCAPE:			
					glfwSetWindowShouldClose(window,GLFW_TRUE);
				break;
				case GLFW_KEY_UP:
					scn->MyRotate(15 ,glm::vec3(1,0,0),0);
					break;
				case GLFW_KEY_DOWN:
					scn->MyRotate(-15 ,glm::vec3(1,0,0),0);
					break;
				case GLFW_KEY_RIGHT:
					scn->MyRotate(15 ,glm::vec3(0,1,0),0);
					break;
				case GLFW_KEY_LEFT:
					scn->MyRotate(-15 ,glm::vec3(0,1,0),0);
					break;
				case GLFW_KEY_F:
					std::cout << "F key was pressed" << std::endl;
					scn->rotateFront();
					break;
				case GLFW_KEY_B:
					std::cout << "B key was pressed" << std::endl;
					scn->rotateBack();
					break;
				case GLFW_KEY_L:
					std::cout << "L key was pressed" << std::endl;
					scn->rotateLeft();
					break;
				case GLFW_KEY_R:
					std::cout << "R key was pressed" << std::endl;
					scn->rotateRight();
					break;				
				case GLFW_KEY_U:					
					std::cout << "U key was pressed" << std::endl;
					scn->rotateUp();
					break;
				case GLFW_KEY_D:
					std::cout << "D key was pressed" << std::endl;
					scn->rotateDown();
					break;
				case GLFW_KEY_SPACE:
					std::cout << "Space key was pressed" << std::endl;
					scn->changeDirection();
					break;
				case GLFW_KEY_A:
					std::cout << "A key was pressed (multiply angle by 2)" << std::endl;
					scn->multiplyAngle(2.0f);
					break;
				case GLFW_KEY_Z:
					std::cout << "Z key was pressed (divide angle by 2)" << std::endl;
					scn->multiplyAngle(0.5f);
					break;

			default:
				break;
			}
		}
	}
	
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Game *scn = (Game*)glfwGetWindowUserPointer(window);

		scn->UpdatePosition((float)xpos,(float)ypos);
		if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
		{
			scn->MouseProccessing(GLFW_MOUSE_BUTTON_RIGHT);
		}
		else if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		{
			scn->MouseProccessing(GLFW_MOUSE_BUTTON_LEFT);
		}
	}


	void window_size_callback(GLFWwindow* window, int width, int height)
	{
		Game *scn = (Game*)glfwGetWindowUserPointer(window);

		scn->Resize(width,height);
		
	}

	void Init(Display &display)
	{
		display.AddKeyCallBack(key_callback);
		display.AddMouseCallBacks(mouse_callback,scroll_callback,cursor_position_callback);
		display.AddResizeCallBack(window_size_callback);
	}
