#pragma once

#include <vector>
#include "Vector.h"
#include "Light.h"
#include "Color.h"
#include "Camera.h"

enum class ObjectType { SPHERE, PLAN, CYLINDER, CONE, MESH, TEXTURE, MESH_TEXTURIZED, MESH2 };
enum class ObjectSurface { ON_SPHERE, ON_PLAN, CYLINDER_SURFACE, CYLINDER_BASE, CYLINDER_TOP, CONE_SURFACE, CONE_BASE, UNKNOWN };


class Object {
protected:

    ObjectType type;
    ObjectSurface surface;

    Vector* kd = nullptr;
    Vector* ke = nullptr;
    Vector* ka = nullptr;
    double shininess;

    double t;
    bool hasIntersection = false;
    Vector* intersectionPoint = nullptr;
    double p0distance;

    double tShadow;
    bool hasIntersectionShadow = false;
    double p0distanceShadow;

public:

    void setKD(Vector* kd);
    Vector* getKD();

    void setKE(Vector* ke);
    Vector* getKE();

    void setKA(Vector* ka);
    Vector* getKA();

    void setShininess(double shininess);
    double getShininess();

    void setObjectType(ObjectType type);
    ObjectType getObjectType();

    void setObjectSurface(ObjectSurface surface);
    ObjectSurface getObjectSurface();

    void setT(double t);
    double getT();

    void setHasIntersection(bool hasIntersection);
    bool getHasIntersection();

    void setIntersectionPoint(Vector* intersectionPoint);
    Vector* getIntersectionPoint();

    void setP0distance(double p0distance);
    double getP0distance();

    void setTShadow(double tShadow);
    double getTShadow();

    void setHasIntersectionShadow(bool hasIntersectionShadow);
    bool getHasIntersectionShadow();

    void setP0distanceShadow(double p0distanceShadow);
    double getP0distanceShadow();

    virtual bool intersect(Vector* p0, Vector* dir) = 0;

    virtual bool intersect_for_shadow(Vector* p0, Vector* dir) = 0;

    virtual Color* getRGB(std::vector<Light*> lights, std::vector<Object*> objects, Vector* p0, Vector* dir, Environment* environmentLight) = 0;

    bool hasShadow(std::vector<Object*> objects, Vector* pi, Vector l, Light* light);

    Color* RGBtoPaint(std::vector<Light*> lights, std::vector<Object*> objects, Vector* p0, Vector* dir, Environment* environmentLight, Vector* normal, Object* obj);

    virtual void rotX(double a) = 0;
    virtual void rotY(double a) = 0;
    virtual void rotZ(double a) = 0;
    virtual void translation(double tx, double ty, double tz) = 0;
    virtual void scaling(double sx, double sy, double sz) = 0;
    virtual void reflectionXY() = 0;
    virtual void reflectionXZ() = 0;
    virtual void reflectionYZ() = 0;

    virtual void doWorldToCamera(Camera* camera) = 0;

    //virtual bool inside(Vector* p) = 0;

    virtual ~Object();
};