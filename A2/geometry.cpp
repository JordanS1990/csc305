#include "geometry.h"
#include <iostream>

#define _USE_MATH_DEFINES

Geometry::Geometry() : mFileName(),
    mFilePath(),
    mModelMatrix(),
    mNormalMatrix(),
    mColorBuffer(0),
    mNormalBuffer(0),
    mTexCoordBuffer(0),
    mVertexBuffer(0),
    mVertexArray(0),
    mPrimitiveType(POINTS),
    mVertices(),
    mNormals(),
    mTexCoords(),
    mColors(),
    mTranslation(),
    mScale(1.0f, 1.0f, 1.0f),
    mRotation()

{
    initOpenGLBuffers();

    initDefaultShader();
}

Geometry::Geometry(std::string m_FilePath) : mFileName(),
    mFilePath(m_FilePath),
    mModelMatrix(),
    mNormalMatrix(),
    mColorBuffer(0),
    mNormalBuffer(0),
    mTexCoordBuffer(0),
    mVertexBuffer(0),
    mVertexArray(0),
    mPrimitiveType(POINTS),
    mVertices(),
    mNormals(),
    mTexCoords(),
    mColors(),
    mTranslation(),
    mScale(1.0f, 1.0f, 1.0f),
    mRotation()

{
    initOpenGLBuffers();

    initDefaultShader();

    this->parseFile();
}

void Geometry::translateX(float m_Translation)
{
    mTranslation.x = m_Translation;
}

void Geometry::translateY(float m_Translation)
{
    mTranslation.y = m_Translation;
}

void Geometry::translateZ(float m_Translation)
{
    mTranslation.z = m_Translation;
}

void Geometry::scaleX(float m_ScaleFactor)
{
    mScale.x = m_ScaleFactor;
}

void Geometry::scaleY(float m_ScaleFactor)
{
    mScale.y = m_ScaleFactor;
}

void Geometry::scaleZ(float m_ScaleFactor)
{
    mScale.z = m_ScaleFactor;
}

void Geometry::rotateX(float m_Degrees)
{
    mRotation.x = (M_PI * m_Degrees) / 180;
}

void Geometry::rotateY(float m_Degrees)
{
    mRotation.y = (M_PI * m_Degrees) / 180;
}

void Geometry::rotateZ(float m_Degrees)
{
    mRotation.z = (M_PI * m_Degrees) / 180;
}

void Geometry::createModelMatrix(bool m_UsePostMultiply)
{
    Matrix4x4 trans = Matrix4x4::Translation(mTranslation.x, mTranslation.y, mTranslation.z);
    Matrix4x4 scale = Matrix4x4::Scale(mScale);
    Matrix4x4 rotx = Matrix4x4::RotationX(mRotation.x);
    Matrix4x4 roty = Matrix4x4::RotationY(mRotation.y);
    Matrix4x4 rotz = Matrix4x4::RotationZ(mRotation.z);

    if(m_UsePostMultiply)
    {
        mModelMatrix = scale * (rotx * roty * rotz) * trans;
    }
    else
    {
        mModelMatrix = trans * (rotx * roty * rotz) * scale;
    }
}
