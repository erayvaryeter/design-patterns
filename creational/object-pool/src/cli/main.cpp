#include <object-pool/object-pool.h>

int main()
{
    auto pool = std::make_shared<ObjectPool<Connection>>(2);

    // Acquire objects from the pool
    auto connection1 = pool->AcquireObject();
    if (connection1)
        connection1->SetConnectionID(1);

    auto connection2 = pool->AcquireObject();
    if (connection2)
        connection2->SetConnectionID(2);

    auto connection3 = pool->AcquireObject();
    if (connection3)
        connection3->SetConnectionID(3);

    // Perform operations on acquired objects
    if (connection1)
        connection1->Connect();

    if (connection2)
        connection2->Connect();

    if (connection3)
        connection3->Connect();

    // Release objects back to the pool
    pool->ReleaseObject(connection1);
    pool->ReleaseObject(connection2);
    pool->ReleaseObject(connection3);

	return 0;
}