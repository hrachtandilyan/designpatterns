#include <iostream>
#include <vector>
#include <queue>

class Object
{
public:
  Object()
    : isActive_(false)
  {
    id_ = count_++;
  }

  ~Object() = default;

  void activate() {
    isActive_ = true;
    std::cout << "Object activated: " << id_ << std::endl;
  }

  void deactivate() {
    isActive_ = false;
    std::cout << "Object deactivated: " << id_ << std::endl;
  }

  bool isActive() const {
    return isActive_;
  }

  unsigned int getID() const {
    return id_;
  }

private:
  unsigned int id_;
  bool isActive_;

  static unsigned int count_;
};

unsigned int Object::count_ = 1;

class GPU_Interface
{
public:
  virtual void bindObject(Object&) = 0;
  virtual void unbindObject(Object&) = 0;

  virtual void render(Object&) = 0;
  virtual unsigned int getMaxObjectHandleAmount() const = 0;

};

class SimpleGPU : public GPU_Interface
{
public:
  SimpleGPU() = default;
  ~SimpleGPU() = default;

  void bindObject(Object& object) override {
    object.activate();
  }

  void unbindObject(Object& object) override {
    object.deactivate();
  }

  void render(Object& object) override {
    if (object.isActive())
      std::cout << "Rendering object (id: " << object.getID() << ") with SimpleGPU..." << std::endl;
    else
      std::cout << "Object (id: " << object.getID() << ") is not activated. Can't render." << std::endl;
  }

  unsigned int getMaxObjectHandleAmount() const override {
    return toHandle_;
  }

private:
  const unsigned int toHandle_{ 10 }; // maximum amount of objects GPU can render

};

class Renderer : public GPU_Interface
{
public:
  Renderer(GPU_Interface* gpu)
    : gpu_(gpu)
  {
  }

  ~Renderer()
  {
    delete gpu_;
  }

  void bindObject(Object& object) override {
    gpu_->bindObject(object);
  }

  void unbindObject(Object& object) override {
    gpu_->unbindObject(object);
  }

  void render(Object& object) override {
    const unsigned int toHandle = gpu_->getMaxObjectHandleAmount();

    if (activeObjects_.size() >= toHandle) {
      Object& obj = *activeObjects_.front();
      activeObjects_.pop();
      unbindObject(obj);
    }

    activeObjects_.push(&object);
    bindObject(object);
    gpu_->render(object);
  }

  unsigned int getMaxObjectHandleAmount() const override {
    return gpu_->getMaxObjectHandleAmount();
  }

private:
  GPU_Interface* gpu_;
  std::queue<Object*> activeObjects_;

};

int main(int argc, char** argv)
{
  Renderer renderer(new SimpleGPU);

  std::vector<Object> objects(15);

  for (auto& object : objects) {
    renderer.render(object);
  }

  return 0;
}