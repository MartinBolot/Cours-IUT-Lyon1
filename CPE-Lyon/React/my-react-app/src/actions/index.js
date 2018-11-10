export const updateSelectedRobot = "UPDATE_SELECTED_ROBOT";
export const updateSelectedPart = "UPDATE_SELECTED_PART";

export const setSelectedRobot = (robot) => {
  return {
    type: updateSelectedRobot,
    obj: robot
  };
}

export const setSelectedPart = (part) => {
  return {
    type: updateSelectedPart,
    obj: part
  }
}
