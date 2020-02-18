#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>

#include <vector>
#include <iostream>

const int SCR_WIDTH= <++>;
const int SCR_HEIGHT = <++>;

//int main( int argc, char** argv )
int main()
{
    if( !glfwInit() )
        return -1;

    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

    GLFWwindow* window = glfwCreateWindow( SCR_WIDTH, SCR_HEIGHT, "<++>", NULL, NULL );
    if( !window )
    {
		std::cerr << "Error on window creating" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent( window );

	std::cout << "GLFW version                : " << glfwGetVersionString() << std::endl;
	std::cout << "GLEW_VERSION                : " << glewGetString( GLEW_VERSION ) << std::endl;
	std::cout << "GL_VERSION                  : " << glGetString( GL_VERSION ) << std::endl;
	std::cout << "GL_VENDOR                   : " << glGetString( GL_VENDOR ) << std::endl;
	std::cout << "GL_RENDERER                 : " << glGetString( GL_RENDERER ) << std::endl;
	std::cout << "GL_SHADING_LANGUAGE_VERSION : " << glGetString( GL_SHADING_LANGUAGE_VERSION ) << std::endl;

    glewExperimental = true;
    GLenum err = glewInit();
    if( err!= GLEW_OK )
    {
		std::cerr << "Glew init failed!" << std::endl;
		std::cerr << "Error: " << glewGetErrorString( err ) << std::endl;
    }

    while( !glfwWindowShouldClose(window) )
    {
        glClearColor( 0, 0, 0, 0 );
        glClear( GL_COLOR_BUFFER_BIT );


        glfwSwapBuffers( window );
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
