const updateSelectedRobot = "UPDATE_SELECTED_ROBOT";
const updateSelectedPart = "UPDATE_SELECTED_PART";

export const setSelectedRobot = (robot) => {
  return {
    type: updateSelectedRobot,
    obj: robot
  };
}
