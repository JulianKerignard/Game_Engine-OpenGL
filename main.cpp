#include <iostream>
#include <ostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


//Callback resize : ajuste le viewport OpenGL
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

//Gestion des entrées clavier
void processInput(GLFWwindow* window) {
    //Échap ferme la fenêtre
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    //Initialisation GLFW
    glfwInit();
    //Configuration OpenGL 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //Requis pour macOS

    //Définition des sommets d'un triangle
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    //Création de la fenêtre 800x600
    GLFWwindow* window = glfwCreateWindow(800, 600, "Ma fenetre de jeu ", NULL, NULL);

    if (window == NULL) {
        std::cout << "Erreur : impossible de creer la fenetre" << std::endl;
        glfwTerminate();
        return -1;
    }
    //Active le contexte OpenGL
    glfwMakeContextCurrent(window);

    //Charge les fonctions OpenGL via GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Erreur : echec initialisation GLAD" << std::endl;
        return -1;
    }

    //Définit le viewport OpenGL (zone de rendu)
    glViewport(0, 0, 800, 600);

    //Enregistre le callback de resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //Génération d'un Vertex Buffer Object (VBO)
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //Boucle de rendu principale
    while(!glfwWindowShouldClose(window)){
        processInput(window);

        //ici mettre fonction de rendu
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //check et call event & swap du buffer
        glfwPollEvents();
        glfwSwapBuffers(window);

    }

    //Nettoyage et fermeture
    glfwTerminate();
    return 0;
}







