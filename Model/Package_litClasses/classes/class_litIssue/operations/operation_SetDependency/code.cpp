if (dependency)
    dependOn.insert(dependOn.begin(),dependentFrom);
else
    dependOn.erase(dependentFrom);