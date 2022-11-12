#include "Sprite.h"

Sprite::Sprite(std::string imageName)
{
	setVertices();
	setIndixs();

	va = new VertexArray();
	vb = new VertexBuffer(positions, 4 * 4 * sizeof(float));

	layout = VertexBufferLayout();
	layout.Push<float>(2);		 //Video: Buffer Layout Abstraction in OpenGL - min 27.30 Explica mas cosas qe se pueden hacer
	layout.Push<float>(2);
	va->AddBuffer(*vb, layout);
	va->Bind();

	ib = new IndexBuffer(indices, 6);

	shaderType = ShaderType::whithTexture;

	shader = new Shader(shaderType);
	shader->Bind();

	texture = new Texture("res/textures/" + imageName);
	texture->Bind();
	shader->SetUniforms1i("u_Texture", 0);

	va->Unbind();
	vb->UnBind();
	ib->UnBind();
	shader->Unbind();
}

Sprite::~Sprite()
{
	delete animation;
}


void Sprite::setVertices()
{
	positions[0] = -50.0f;
	positions[1] = -50.0f;
	positions[5] = -50.0f;
	positions[4] = 50.0f;
	positions[8] = 50.0f;
	positions[9] = 50.0f;
	positions[12] = -50.0f;
	positions[13] = 50.0f;

	positions[2] = 0.0f;
	positions[3] = 0.0f;
	positions[6] = 1.0f;
	positions[7] = 0.0f;
	positions[10] = 1.0f;
	positions[11] = 1.0f;
	positions[14] = 0.0f;
	positions[15] = 1.0f;

}

void Sprite::setVerticesSpriteSheet()
{
	//Crear animaciones y 
	positions[0] = -50.0f;
	positions[1] = -50.0f;
	positions[5] = -50.0f;
	positions[4] = 50.0f;
	positions[8] = 50.0f;
	positions[9] = 50.0f;
	positions[12] = -50.0f;
	positions[13] = 50.0f;

	positions[2] = 0.0f;
	positions[3] = 0.0f;
	positions[6] = 1.0f;
	positions[7] = 0.0f;
	positions[10] = 1.0f;
	positions[11] = 1.0f;
	positions[14] = 0.0f;
	positions[15] = 1.0f;

}

void Sprite::setIndixs()
{
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 2;
	indices[4] = 3;
	indices[5] = 0;
}

void Sprite::calculateVertices()
{
}

void Sprite::CreateAnimation(int x, int y, int durationInSec, int framesAmountX, int framesAmountY)
{
	animation = new Animation();

	animation->addFrame(x, y, texture->GetWidth() / framesAmountX, texture->GetHeight() / framesAmountY, texture->GetWidth(), texture->GetHeight(), durationInSec, framesAmountX);


}

void Sprite::updateAnimation(Timer& timer)
{
	frames = animation->getFrames();

	positions[2] = frames[animation->getCurrentIndex()].uvCoords[0].u;
	positions[3] = frames[animation->getCurrentIndex()].uvCoords[0].v;
	
	positions[6] = frames[animation->getCurrentIndex()].uvCoords[1].u;
	positions[7] = frames[animation->getCurrentIndex()].uvCoords[1].v;
	
	positions[10] =frames[animation->getCurrentIndex()].uvCoords[3].u;
	positions[11] =frames[animation->getCurrentIndex()].uvCoords[3].v;
	
	positions[14] =frames[animation->getCurrentIndex()].uvCoords[2].u;
	positions[15] =frames[animation->getCurrentIndex()].uvCoords[2].v;

	animation->UpdateAnimation(timer);

	vb->updateVertexBufferData(positions, 4 * 4 * sizeof(float));
}


