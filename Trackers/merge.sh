#!/bin/bash

export https_proxy=http://127.0.0.1:7890

cd trackerslist
git pull

cd ../TrackersListCollection
git pull

cd ..
cat trackerslist/trackers_all.txt TrackersListCollection/all.txt > trackers.txt
