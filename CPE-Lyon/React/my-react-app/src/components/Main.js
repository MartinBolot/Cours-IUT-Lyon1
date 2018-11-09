import React, { Component } from 'react';
import { connect } from 'react-redux';
import '../App.css';
import '../lib/bootstrap-3.3.7-dist/css/bootstrap.min.css';
import LeftSide from "./LeftSide/LeftSide";
import MiddleSide from "./MiddleSide/MiddleSide";
import RightSide from "./RightSide/RightSide";
import * as jsonSource from "../sources/robots_parts";

class Main extends Component {
  constructor(props) {
    super(props);
    this.state = {
      part: null,
      selectedPartId: null,
    };
    this.handleMiddleSideClick = this.handleMiddleSideClick.bind(this);
  }

  handleMiddleSideClick(id) {
    const selectedPart = jsonSource.parts.filter((part) => {
      return part.id === id;
    });
    this.setState({
      part: selectedPart[0],
      selectedPartId: id
    });
  }

  render() {
    let filteredParts;
    if(this.props.selectedRobotId) {
      const robot = jsonSource.robots.filter((robot) => {
        return robot.id === this.props.selectedRobotId;
      })[0];
      filteredParts = jsonSource.parts.filter((part) => {
        // does the robots have this part ?
        return (
          robot.parts ? robot.parts.includes(part.id) : false
        );
      });
    }
    else {
      filteredParts = this.props.parts;
    }

    return (
      <div className="container-fluid">
        <div className="row">
          <h1>Welcome to robot shop</h1>
        </div>
        <div className="row">
            <div className="col-md-4 col-lg-4">
              <LeftSide
                robots={jsonSource.robots}
                selectedRobotId={this.props.selectedRobotId}
              />
            </div>
            <div className="col-md-4 col-lg-4">
              <MiddleSide
                parts={filteredParts}
                selectedPartId={this.state.selectedPartId}
                handleMiddleSideClick={this.handleMiddleSideClick}/>
            </div>
            <div className="col-md-4 col-lg-4" >
              <RightSide
                part={this.state.part}
                selectedPartId={this.state.selectedPartId}
              />
            </div>
        </div>
      </div>
    );
  }
}

const mapStateToProps = (state, ownprops) => {
  return {
    selectedRobotId: state.robotReducer.id
  }
};

export default connect(mapStateToProps)(Main);
