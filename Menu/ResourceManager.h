//
// Created by Cameron on 4/27/2020.
//

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <unordered_map> // To keep track of images
#include <fstream>
#include <string>

using namespace std;


template <typename Derived, class T>
class ResourceManager
{
public:

    ResourceManager(const string& fileName) // fileName will be used to pass in textures
    {
        populateStorage(fileName); // populates the file that's passed in
    }

    bool AddResource(const string& resName)
    {
        auto Res = Find(resName);

        if (Res) // if resName is already allocated
        {
            // tells resMap if a second object is found
            ++Res->second; // increments the counter in map
        }

        auto fPath = fMap.find(resName);

        // Makes sure the file path that is input is valid
        if (fPath == fMap.end()) // if we don't find resource
            return false;
        
        T* resource = load(fPath->second);

        if (!resource) // if the resource doesn't load it returns false
            return false;

        // emplace inserts new element in map if its key is unique
        resMap.emplace(resName, make_pair(resource, 1));

        return true;
    }

    T* GetResource(const string& resName)
    {
        // Auto since unsure what datatype Find() returns
        auto Res = Find(resName);

        if (Res)
            return Res->first; // returning first element
        else
            return NULL;
    }

    bool ReleaseResource(const string& resName)
    {
        auto Res = Find(resName);

        if (!Res)
            return false;

        --Res->second; // decrement

        if (!Res->second)
            Unload(resName); // de-allocate memory

        return true;
    }

    // Wipe heap allocation whenever we terminate
    void wipeResources()
    {
        while(resMap.begin() != resMap.end())
        {
            delete resMap.begin()->second.first;
            resMap.erase(resMap.begin());
        }
    }

    // To load every resource we use differently (how they want to load)
    T* load(const string& Path)
    {
        // Items passed into Derived at the top of class template are used by the load() function
        return static_cast<Derived*>(this)->load(Path);
    }

    // Destructor
    ~ResourceManager()
    {
        wipeResources(); // de-allocate resources from heap
    }



private:

    std::unordered_map< std::string, std::pair<T*, int> > resMap; // pair of resource type + counter

    std::unordered_map<std::string, std::string> fMap; // stores all resources when initialized

    // Find function
    pair<T*, int>* Find(const string& resName)
    {
        auto iteration = resMap.find(resName);

        if (iteration != resMap.end())
            return &iteration->second;
        else
            return NULL;
    }

    // Unload function
    void Unload(const string& resName)
    {
        auto iteration = resMap.find(resName);

        if (iteration == resMap.end())
        {
            cerr << "Failed to unload" << endl;

            return;
        }

        delete iteration->second.first;

        resMap.erase(iteration);
    }

    // Populate fMap
    void populateStorage(const string& fileName)
    {
        ifstream Paths(fileName);

        if (Paths.is_open()) // making sure the paths are open
        {
            string pName;
            string Path;

            while (!Paths.eof()) // while the paths are not ended
            {
                Paths >> pName >> Path;
                fMap.emplace(pName, Path);
            }

            Paths.close();

            return;
        }

        cerr << "Failed to populate" << endl;
    }

};


#endif //RESOURCEMANAGER_H
