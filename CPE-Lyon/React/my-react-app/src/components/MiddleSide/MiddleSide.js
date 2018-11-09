import React, { Component } from 'react';
import Part from "../Part/Part";

class MiddleSide extends Component {
  constructor(props) {
    super(props);
    this.handlePartClick = this.handlePartClick.bind(this);
  }
  handlePartClick(id) {
    this.props.handleMiddleSideClick(id);
  }
  render() {
      return this.props.parts.map((part, index) => {
          return (
            <Part
              key={index}
              part={part}
              selected={this.props.selectedPartId === part.id}
              handlePartClick={this.handlePartClick}
            />
          );
      });
  }
}

export default MiddleSide;
