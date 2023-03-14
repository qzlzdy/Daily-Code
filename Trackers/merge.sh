#!/bin/bash
cd trackerslist
git pull
cd ../TrackersListCollection
git pull
cd ..
cat trackerslist/trackers_all.txt TrackersListCollection/all.txt > trackers.txt

